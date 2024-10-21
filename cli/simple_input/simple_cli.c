#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wiringPi.h>

#define COMMAND 20

void print_usage() {
    printf("Available commands:\n");
    // TODO: Тут нужен список команд для справки
    printf("Available commands:\n");
}

int handle_command(char* command) {

}

int main(int argc, char* argv[]) {
    bool state = 0;

    if (wiringPiSetup() == -1) {
        printf("Error initialization wiringPi");
        return 1;
    }

    while (1) {
        if (!state) {
            printf("\nEnter command: ");
            state = 1;
        }

        if (handle_command()) {} // TODO: Остановился тут
    }
}