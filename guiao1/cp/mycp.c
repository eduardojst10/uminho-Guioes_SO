#include <stdlib.h>
#include <sys/types.h>  
#include <fcntl.h>
#include <unistd.h>


int mycp(char const * from_path,char const * to_path,int buffer_size){
    int from_fd = open(from_path, O_RDONLY);

    int to_fd  = open(to_path,O_CREAT | O_TRUNC | O_WRONLY,0644); //0644 são as permissões de leitura e de escrita

    char *buffer = (char *)malloc(sizeof(char) * buffer_size);

    ssize_t write_bytes = 0;
    ssize_t read_bytes = 0;
    ssize_t bytes = 0;
    while ((bytes = read(from_fd,buffer,12) > 0)){
        read_bytes +=bytes;
        write_bytes+= write(to_fd,buffer,12);
    
    }
    close(from_fd);
    close(to_fd);
    free(buffer); //libertar este espaço de memoria
    
    if(write_bytes - read_bytes != 0) return -1;

    return 0;
}
