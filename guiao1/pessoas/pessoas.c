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
    
    if(write(fd,&pessoa,sizeof(struct pessoa)) < 1){ //buffer é um apontador 
        puts("Error - Nada escrito"); //stdout
        close(fd);
        return 1;

    }
    /*
    struct stat st;
    fstat(fd, &st);
    off_t filesize = st.st_size;
    int pos = (int)filesize / sizeof(struct pessoa);
    */
    puts("Sucesso ");
    close(fd);
    return 0;

}

int altera_Idade(char* nome,int idade,int fd){
    Pessoa p;
    int bytes_read;
    int res;

    while((bytes_read) = read(fd,&p,sizeof(struct pessoa))){

        if(strcmp(p.nome,nome)==0){
                    res = lseek(fd,-sizeof(Pessoa),SEEK_CUR);
                    if(res<0){
                        perror("Error lseek");
                        return -1;
                    }

                    p.idade = idade;
                    res = write(fd,&p,sizeof(Pessoa));
                    if(res < 0){
                        perror("Error write");
                        return -1;
                    }
        }
    }
    
        
    };

    
    return 0;
}
