#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int *pids;
int files_count;
int timeout;

void timeout_handler(int signum) {
    for (int i = 0; i < files_count; i++) {
        printf("killing grep %d\n", pids[i]);
        
        if (pids[i] > 0) { 
            kill(pids[i], SIGKILL);
        }
    }

    timeout = 1;
}


// Exit status:
// 0 -> found
// 1 -> not found
// >1 -> error
int main(int argc, char *argv[]) {

    if (argc < 2) {
        perror("Usage: multigrep <palavra> <file> ...");
        exit(2);
    }

    files_count = argc - 2;
    char** files = argv + 2;
    pids = malloc(sizeof(int) * files_count);


    // Create grep processes. One per file.

    for (int i = 0; i < files_count; i++) {
        int pid = -1;
        if ((pid = fork()) == 0) {
            printf("grep #%d with pid %d for file %s\n", i, getpid(), files[i]);
            if (execlp("grep", "grep", argv[1], files[i], NULL) < 0) {
                perror("exec grep");
                exit(10);
            }
        }

        pids[i] = pid;
    }

    if(signal(SIGALRM, timeout_handler) == SIG_ERR) {
        perror("timeout handler");
        return 10;
    }

    alarm(10);

    // Many greps executing...

    int status = 0;
    int found = 0;
    int pid = -1;
    while (!found && (pid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            switch (WEXITSTATUS(status)) {
                case 0:
                    // grep found the word.
                    found = 1;
                    printf("grep with pid %d found the word.\n", pid);
                    break;
                case 1:
                    // grep did not find the word.
                    printf("grep with pid %d did not find the word.\n", pid);
                    break;
            }
        } 
    }

    if (timeout) {
        return 5;
    }

    // Few greps may be running...

    if (!found)
        return 1;
    
    for (int i = 0; i < files_count; i++) {
        printf("Trying to kill grep with pid %d\n", pids[i]);
        
        if (pid != pids[i] && pids[i] > 0) { // pids[i] > 0 prevents kill(-1, ...)
            kill(pids[i], SIGKILL);
            
            if (waitpid(pids[i], &status, 0) > 0) {
                if (WIFEXITED(status)) {
                    printf("grep %d finished.\n", pids[i]);
                } else {
                    printf("grep %d was killed.\n", pids[i]);
                }
            }
        }
    }

    free(pids);

    return 0;
}
