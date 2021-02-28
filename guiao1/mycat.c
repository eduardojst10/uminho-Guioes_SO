#include <stdlib.h>
#include <sys/types.h>  
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


int mycat(){
    
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);

    ssize_t write_bytes = 0;
    ssize_t read_bytes = 0;
    ssize_t bytes = 0;
    while ((bytes = read(0,buffer,BUFFER_SIZE) > 0)){ //0 - do teclado
        read_bytes +=bytes;
        write_bytes+= write(1,buffer,BUFFER_SIZE); //1 -para o stdout
    
        //write(STDOUT_FILENO,buffer,bytes_read);
    }
    free(buffer);
    
    if(write_bytes - read_bytes != 0) return -1;

    return 0;
}
