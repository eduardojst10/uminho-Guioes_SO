#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 


int main(){
    pid_t pid;
    int status;

    
    for(int i=1 ; i<11; i++){
        if((pid = fork() == 0)){         
         pid_t Pid_filho = getpid();    
         pid_t Pid_pai = getppid();
	     printf("[FILHO] pid= %d  -> [PAI] pid= %d\n",Pid_filho,Pid_pai);
         _exit(i); //vai terminar o programa i

        }else{
            pid_t pid_terminates = wait(&status);//vai esperar pelo filho i
            printf("----[PAI] process %d exited. exit code: %d----\n",pid_terminates,WEXITSTATUS(status));
        }
    }

    return 0;
}

/*
int main(int argc, char const *argv[]) {
    for(int i = 1; i < 11; i++) {
        if(fork() == 0) {
            pid_t PID = getpid();
            pid_t PPID = getppid();
            printf("Child PID = %d\nChild's parent PID = %d\n", PID, PPID);
            _exit(i);
        }
        int exit_status;
        wait(&exit_status);
        printf("%d\n",WEXITSTATUS(exit_status));
    }
    return 0;
}

*/