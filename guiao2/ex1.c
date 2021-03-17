#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int main(){
    pid_t pid;

    if((pid = fork()) == 0){
        //processo filho
        printf("[FILHO] pid: %d\n",getpid());
        

    }else{
        //código pai
        printf("[PAI] pid: %d\n",getpid());
        printf("[PAI]: pid do meu filho %d\n",pid);
    }

    return 0;
}