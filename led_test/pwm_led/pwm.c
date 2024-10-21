#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>  // для usleep

#define LED_PIN 2  // Замените на ваш пин

void pwm_led(int duty_cycle, int period) {
    int on_time = (duty_cycle * period) / 100;  // время включения
    int off_time = period - on_time;            // время выключения

    digitalWrite(LED_PIN, HIGH);
    usleep(on_time * 1000);  // Время в микросекундах

    digitalWrite(LED_PIN, LOW);
    usleep(off_time * 1000);
}

int main(void) {
    if (wiringPiSetup() == -1) {
        printf("Ошибка инициализации WiringPi!\n");
        return 1;
    }

    pinMode(LED_PIN, OUTPUT);

    int duty_cycle = 0;
    int direction = 1;
    int period = 20;  // Период ШИМ в миллисекундах

    while (1) {
        pwm_led(duty_cycle, period);

        // Плавное изменение duty cycle
        duty_cycle += direction;
        if (duty_cycle >= 100 || duty_cycle <= 0) {
            direction = -direction;
        }

        usleep(5000);  // Задержка между изменениями яркости
    }

    return 0;
}