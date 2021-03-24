#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 


int main(int argc, char** argv){
    int ret;
    //ret = execl("/bin/ls","ls","-l",NULL);
    

    char *exargs[] = {"ls","-ls",NULL};
    //ret = execv("/bin/ls",exargs);
    ret = execvp("ls",exargs);
    //Não é executado dps de qualquer exec()
    printf("Done."); //ou seja este printf n aparece

    return 0;
}