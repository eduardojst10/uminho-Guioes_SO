#include "mynl.h"

int main(int argc,char* argv){
    int to_fd  = open(argv[1],O_CREAT | O_TRUNC | O_WRONLY,0644);
    
    if(argc < 3){
        printf("usage: mynl <from_path> <buffer_size> \n");
        return 1;
    }

    return mynl(to_fd,1024); //atoi permite garantir que seja o int

}
