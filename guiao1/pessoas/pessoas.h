#ifndef PESSOAS_H
#define PESSOAS_H

typedef struct pessoa{
    char nome[200];
    int idade;
}Pessoa;


int inserePessoa(char* nome, int idade,int fd);
int altera_Idade(char* nome,int idade,int fd);

#endif