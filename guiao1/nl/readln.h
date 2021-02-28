#ifndef READLN_H
#define READLN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fd, char *line,size_t size);
ssize_t readlnEnhc(int fd, char *line,size_t size);


#endif
