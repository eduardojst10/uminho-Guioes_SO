#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "pessoas.h"

int inserePessoa(char* nome, int idade,int fd){

    if(fd == -1) {
                puts("ERROR - Couldn't open or create registry file.");
                return 1;
            }

    Pessoa pessoa;
    pessoa.idade = idade;
    strcpy(pessoa.nome,nome);
    
    if(write(fd,&pessoa,sizeof(struct pessoa)) < 1){
        puts("Error - Nada escrito"); //stdout
        close(fd);
        return -1;

    }

    return 0;

}
