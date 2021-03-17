#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int main(){
    pid_t pid;
    int status;

    if((pid = fork()) == 0){
        //processo filho
        //printf("[FILHO] pid: %d\n",getpid());
        //printf("[FILHO]: pid do meu pai %d\n",getppid());
        printf("[FILHO]: pid %d ; pai %d\n",getpid(),getppid());
        _exit(-1);
    }else{
        //código pai
        //printf("[PAI] pid: %d\n",getpid());
        //printf("[PAI]: pid do meu pai %d\n",getppid());
       // printf("[PAI]: pid do meu filho %d\n",pid);
       pid_t terminated_pid = wait(&status);
       printf("----[PAI] process %d exited. exit code: %d----\n",terminated_pid,WEXITSTATUS(status));
    }

    return 0;

}