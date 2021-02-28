#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "pessoas.h"

int main(int argc, char *argv[]){
    if(argc < 4){
        puts("Error not enough arguments");
        return -1;
    
    }

    int no_output = 0 ;
    if(argc == 5) {
        if(strcmp(argv[4],"--no-output") == 0) {
            no_output = 1;
        }
    }

    switch (*(argv[1]+1))
    {
    case 'i':
    
        if(inserePessoa(argv[2], atoi(argv[3]),"registo.txt")== -1){
            puts("ERROR - Couldn't open or create registry file.");
                return -1;
        } 
        break;
    
    case 'u':
        break;
    default:
        break;
    }




}