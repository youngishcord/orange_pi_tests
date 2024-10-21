#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>  // для usleep
#include <stdbool.h>

#define LED_PIN 2  // Замените на ваш пин

bool state = false;

int brightnes = 0;

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("Ошибка инициализации WiringPi!\n");
        return 1;
    }

    while (1) {
        digitalWrite(LED_PIN, HIGH);
        usleep(1000);

        digitalWrite(LED_PIN, LOW);
        usleep(brightnes);

        brightnes += 100;
        printf("%d\n", brightnes);
    }

    return 0;
}