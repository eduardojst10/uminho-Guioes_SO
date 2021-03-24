#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <string.h>

int main(int argc, char** argv){

    int ret;
    argv[0] = "EX3"; //o executavel manteve-se o mesmo mas é o mesmo
    ret = execvp("./ex3",argv);
    printf("Result: %d",ret);
    return 0;

}   
    
    
    
 /*
    //char* args[1024]= "./ex3"
    char *exargs[1024];
    exargs[0] = "./3";
    char buffer[1024];
    int i=1;

    while(read(1,buffer,1024)){
        exargs[i] = strdup(buffer);
        i++;
    }
    exargs[i] = NULL;

    execv("./guiao3",exargs);

    return 0;
*/