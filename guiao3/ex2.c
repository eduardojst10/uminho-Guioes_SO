#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 


int main(int argc, char** argv){
    int ret,status;
    pid_t pid;
    //ret = execl("/bin/ls","ls","-l",NULL);
    
    if((pid=fork()==0)){
        printf("SON: %d\n",getpid());
        char *exargs[] = {"ls","-ls",NULL};
        ret = execvp("ls",exargs);
        _exit(ret);
    }else{
        printf("FATHER: %d\n",getpid());
        pid_t terminated = wait(&status);
        if(WIFEXITED(status)){
            printf("Filho terminou %d st=%d",terminated,WEXITSTATUS(status));
        }else{
            printf("Asneira\n");
        }
        return 0;
    }

   






    //ret = execv("/bin/ls",exargs);
    //Não é executado dps de qualquer exec()
    printf("Done."); //ou seja este printf n aparece

    return 0;
}