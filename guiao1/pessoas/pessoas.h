#ifndef PESSOAS_H
#define PESSOAS_H

typedef struct pessoa{
    char* nome;
    int idade;

    

}Pessoa;


int inserePessoa(char* nome, int idade,char const *to_path);


#endif