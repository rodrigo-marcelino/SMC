/*
    Rodrigo Martins Marcelino - 211321354
    01. Led piscando + Push btn
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <wiringPi.h>

// Definição das portas onde estarão os periféricos
#define PIN_LED 19 // GPIO19
#define PIN_INP_BTN 26 // GPIO26
#define DEBOUNCE_INTERVAL 200

// Variáveis de controle para lógica de interrupção
volatile bool pushed = false;
volatile int pushCounter = 0;
volatile unsigned long lastInterrupt = 0;

void configureIO(void);

// Função que executa a interrupção -> chamada quando o btn é pressionado 
void btnInterrupt(void) {
    unsigned long currentInterrupt = millis();

    if ((currentInterrupt - lastInterrupt) > DEBOUNCE_INTERVAL) {
        pushCounter++;
        pushed = !pushed;
        lastInterrupt = currentInterrupt;
    }
}

int main(int argc, char *argv[]) {
    if (wiringPiSetupGpio() < 0) {
        fprintf(stdout, "Erro: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    configureIO();

    // Configura a interrupção -> evento que dispara a função btnInterrupt
    // PIN_INP_BTN: pino para o qual a interrupção será configurada
    // INT_EDGE_FALLING: 
    //  &btnInterrupt: endereço da função a ser executada
    if (wiringPiISR(PIN_INP_BTN, INT_EDGE_FALLING, &btnInterrupt) < 0) {
        fprintf(stdout, "Erro ao configurar interrupção.\n");
        return EXIT_FAILURE;
    }

    while (true) {
        if (pushed == true) {
            digitalWrite(PIN_LED, HIGH);
            delay(500);
            digitalWrite(PIN_LED, LOW);
            delay(500);
        } else {
            digitalWrite(PIN_LED, LOW);
        }
    }
    
    return EXIT_SUCCESS;
}

    // Configuração das GPIOs
    void configureIO(void) {
        pinMode(PIN_LED, OUTPUT);
        pinMode(PIN_INP_BTN, INPUT);
        pullUpDnControl(PIN_INP_BTN, PUD_UP);
    }