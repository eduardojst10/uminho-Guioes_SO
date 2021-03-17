#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int main(){
    pid_t pid;
    int status;

    for(int i = 1; i<=10;i++){
        
        if((pid = fork()==0)){
           printf("[FILHO] pid= %d  -> [PAI] pid= %d\n",getpid(),getppid());
            sleep(2);
            _exit(i);
        }
    }

    for(int i=1; i<=10;i++){
        pid_t terminated = wait(&status);
        if(WIFEXITED(status)){
            printf("[FILHO]- %d | Exit com status %d\n",terminated,WEXITSTATUS(status));
        }else printf("Unknown Error \n");
    }

    return 0;
}

