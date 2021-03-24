#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 


int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: program <needle>\n");
        exit(-1);
    }


    for(int i = 0; i<rows;i++){
        if((pid=fork())==0){
            printf("[pid %d] row: %d\n",getpid(),i);

            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == needle){
                    _exit(i);
                }
            }
            _exit(-1);
        }
    }

    for(int i= 0; i < rows;i++){
        pid_t terminated_pid = wait(&status);

        if(WIFEXITED(status) < 255){ // o estado que devolvemos só tem 8 bits o caso especial -1. AO dizer que é menor que 255 é dizer qu eé diferente de -1, significa que o processo encontrou o numero na linha correspodente
            printf("[pai process %d exited. found number at row: %d\n",terminated_pid,WEXITSTATUS(status));
        
        }else {
            printf()
        } 
    }
}