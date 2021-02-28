#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>





ssize_t readln(int fd, char *line,size_t size){
    ssize_t c = 0;

    while(c < size -1){
        ssize_t bytes_read = read(fd,&line[c],1); //&line[c] pointer para um buffer com 1 caracter
        if(bytes_read < 0) break;   
        if(line[c++] == '\n') break;
    }
    line[c] = 0;
    return c;
}

ssize_t readlnEnhc(int fd, char *line,size_t size){
    ssize_t bytes_read = read(fd,line,size);

    if(bytes_read){                                      //strcspn numero de bytes que line contém que não estão no segundo parametro em reject
           size_t length_linha = strcspn(line,"\n")+1; //size_t strcspn(const char *s, const char *reject);
            if(bytes_read < length_linha) length_linha = bytes_read;
            line[length_linha] = 0;
            lseek(fd,length_linha - bytes_read,SEEK_CUR); //repõe o file descriptor  mas como é que ele repõe
            return length_linha;

    }else return 0;
}


