#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/wait.h> 

int main(int argc, char** argv){

    int ret,status;
    pid_t pid;
    for(int i=1; i< argc; i++){
        if((pid = fork())==0){
            printf("[FILHO]: %d , comando; %d\n",getpid(),argv[i]);
            ret=execlp(argv[i],argv[i],NULL);
            _exit(-1);
        }
    }

    for(int i=1; i<argc;i++){
        pid_t terminated = wait(&status);
        if(WIFEXITED(status)){
            printf("Filho terminou %d st=%d\n",terminated,WEXITSTATUS(status));

        }else{
            printf("Error status");
        } 
    }
    printf("TODOS OS PROCESSOS FORAM TERMINANDOS")

    return 0;
}