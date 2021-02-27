#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define SIZE 1024


void mycat(int argc, char const argv){
    char* buffer[SIZE] ;
    int fd = open(argv,"O_RDONLY",6600);

    ssize_t bytes_read = 0;
    

    while((bytes_read = read(fd,buffer,SIZE))){
        write(1,buffer,bytes_read);
    }



}




