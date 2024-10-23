#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    bool running = 1;
    char command[30];
    int pin, state;

    while (running)
    {
        printf("Enter the command:\n");
        printf(">");

        scanf("%s %d %d", command, &pin, &state);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the program\n");
            running = 0;
        }

        if (strcmp(command, "setpin") == 0) {
            printf("data -> %d, %d\n", pin, state);
        }
    }
    
    return 0;
}