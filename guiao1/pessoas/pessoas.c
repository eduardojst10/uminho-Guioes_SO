#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "pessoas.h"

int inserePessoa(char* nome, int idade,char const *to_path){
    int fd = open(to_path,O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

    if(fd == -1) {
                puts("ERROR - Couldn't open or create registry file.");
                return 1;
            }

    ssize_t bytes = 0;
    Pessoa pessoa;
    pessoa.idade = idade;
    strcpy(pessoa.nome,nome);
    
    if(write(fd,&pessoa,sizeof(struct pessoa)) < 1){
        puts("Error - Nada escrito"); //stdout
        close(fd);
        return -1;

    }

    //This little section gets the file size, and then divides it by the struct size, to get the number of people in the registry, aka, the index of the most recent entry.
        struct stat st; //struct original de c que dá return de informações do nosso file 
        fstat(fd, &st); 
        off_t filesize = st.st_size; //vai ficar como offset
        int pos = (int) filesize / sizeof(struct pessoa); //numero de pessoas que temos
        close(fd);
        return pos;

}
