#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int time = 0;
int counter = 0;


void printTime(int signum) {
    printf("time: %ds\n", time);
    counter++;
}

void endProgram(int signum) {
    printf("interruptions: %d\n", counter);
    exit(0);
}

void secondsInc(int signum) {
    time++;
    alarm(1);
}


int main(int argc, char *argv[]) {
    if (signal(SIGINT, printTime) == SIG_ERR) {
        perror("SIGINT failed");
        exit(-1);
    }
    if (signal(SIGQUIT, endProgram) == SIG_ERR) {
        perror("SIGQUIT failed");
        exit(-2);
    }
    if (signal(SIGALRM, secondsInc) == SIG_ERR) {
        perror("SIGALRM failed");
        exit(-3);
    }

    alarm(1);
    while(1)
        pause();

    return 0;
}
