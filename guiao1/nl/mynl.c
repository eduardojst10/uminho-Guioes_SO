#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include "readln.h"

int mynl(char const *from_path,int buffer_size){
    int fd = open(from_path,O_RDONLY);

    char* buffer = (char*)malloc(sizeof(char)*buffer_size);
    ssize_t bytes = 0;
    int i = 0;

    while((bytes = readlnEnhc(fd,buffer,buffer_size) > 0)){
        char lin[100];
        sprintf(lin,"%d.",6,i++);
        write(1,lin,strlen(lin));
        write(1,lin,bytes);

    }

    close(fd);
    return 0;
}