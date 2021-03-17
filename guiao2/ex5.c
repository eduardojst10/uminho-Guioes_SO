#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 

int main(){
    
    int status;
    pid_t res_fork;
    for(int i = 1; i<=10;i++){
        if((res_fork = fork()==0)){
            printf("[%d]--[FILHO]- %d | My father is %d\n",i,getpid(),getppid());
            
        }else{
            pid_t t_pid = wait(&status);
            printf("[%d]--FATHER #%d; my son is %d\n",i,getpid(),t_pid);
            _exit(i);
        }
    }

    printf("HELLO WORLD\n");
    _exit(0);
    return 0;
}


