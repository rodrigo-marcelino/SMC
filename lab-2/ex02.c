#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <wiringPi.h>

// Definição das portas onde estarão os periféricos
#define PIN_LED 19 // GPIO19
#define PIN_INP_BTN 26 // GPIO26
#define PIN_INP_ADD 21 // GPIO20
#define DEBOUNCE_INTERVAL 200

volatile bool pushed = false;
volatile int pushCounter = 0;
volatile unsigned long lastInterrupt = 0;

volatile bool addPushed = false;
volatile int addCounter = 0;
volatile unsigned long lastInterruptAdd = 0;

int atraso = 500;

void configureIO(void);

void btnInterrupt(void) {
    unsigned long currentInterrupt = millis();
    if ((currentInterrupt - lastInterrupt) > DEBOUNCE_INTERVAL) {
        pushCounter++;
        pushed = !pushed;
        lastInterrupt = currentInterrupt;
    }
}

void btnAddInterrupt(void) {
    unsigned long currentInterrupt = millis();
    if ((currentInterrupt - lastInterruptAdd) > DEBOUNCE_INTERVAL) {
        addCounter++;
        addPushed = !addPushed;
        lastInterruptAdd = currentInterrupt;
    }
}

int main(int argc, char *argv[]) {
    if (wiringPiSetupGpio() < 0) {
        fprintf(stdout, "Erro: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    configureIO();

    if (wiringPiISR(PIN_INP_BTN, INT_EDGE_FALLING, &btnInterrupt) < 0) {
        fprintf(stderr, "Erro ao configurar interrupção do botão.\n");
        return EXIT_FAILURE;
    }

    if (wiringPiISR(PIN_INP_ADD, INT_EDGE_FALLING, &btnAddInterrupt) < 0) {
        fprintf(stderr, "Erro ao configurar interrupção do botão de adição.\n");
        return EXIT_FAILURE;
    }

    while (true) {
        if (pushed == true) {
            digitalWrite(PIN_LED, HIGH);
            delay(atraso);
            digitalWrite(PIN_LED, LOW);
            delay(atraso);
        } else {
            digitalWrite(PIN_LED, LOW);
        }

        if (addPushed == true) {
            atraso += 100;
            if (atraso > 1000) {
                atraso = 100;
            }
            addPushed = false;
        }
    }

    return EXIT_SUCCESS;
}

void configureIO(void) {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_INP_BTN, INPUT);
    pinMode(PIN_INP_ADD, INPUT);
    pullUpDnControl(PIN_INP_BTN, PUD_UP);
    pullUpDnControl(PIN_INP_ADD, PUD_UP);
}