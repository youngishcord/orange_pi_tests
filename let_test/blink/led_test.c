#include <wiringPi.h>
 
#define PIN_LED 2
#define ESPERA 1000 // 1s
 
int main (void)
{
    wiringPiSetup();
    pinMode(PIN_LED, OUTPUT);
    while(1)
    {
        digitalWrite(PIN_LED, HIGH);
        delay(ESPERA);
        digitalWrite(PIN_LED, LOW);
        delay(ESPERA);
    }
    return 0;
}