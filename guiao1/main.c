#include <stdlib.h>
#include <stdio.h>  
#include "mycp.h"

 // const faz com que a memoria alocada para argv nao seja alterada
int main(int argc, char const *argv[]){

    if(argc < 4){
        printf("usage: mycp <from_path> <to_path> <buffer_size> \n");
        return 1;
    }

    return mycp(argv[1],argv[2],atoi(argv[3])); //atoi permite grarntir que seja o int
} 
