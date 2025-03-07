#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <wiringPi.h>

// Definição das portas onde estarão os periféricos
#define PIN_LED1 5 // GP105
#define PIN_LED2 6 // GP106
#define PIN_LED3 13 // GP1013
#define PIN_LED4 19 // GP1019
#define PIN_INP_BTN 26 // GP1026

#define DEBOUNCE_INTERVAL 200

volatile bool pushed = false;
volatile int pushCounter = 0;
volatile unsigned long lastInterrupt = 0;

void configureIO(void) {
  // Configuração das portas como saída para os LEDs e entrada para o botão
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_INP_BTN, INPUT);
}

void btnInterrupt(void) {
  unsigned long currentInterrupt = millis(); // Obtém o tempo atual em milissegundos
  if ((currentInterrupt - lastInterrupt) > DEBOUNCE_INTERVAL) {
    pushCounter++;
    pushed = !pushed; // Inverte o estado do botão
    lastInterrupt = currentInterrupt;
  }
}

int main(int argc, char *argv[]) {
  if (wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Erro ao inicializar wiringPi: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  configureIO();

  if (wiringPiISR(PIN_INP_BTN, INT_EDGE_FALLING, btnInterrupt) < 0) {
    fprintf(stderr, "Erro ao configurar interrupção: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  while (true) {
    switch (pushCounter) {
      case 1: // Apenas o primeiro LED  aceso
        digitalWrite(PIN_LED1, HIGH);
        break;
      case 2: // Apenas o segundo LED aceso
        digitalWrite(PIN_LED1, LOW);
        digitalWrite(PIN_LED2, HIGH);
        break;
      case 3: // Apenas o terceiro LED aceso
        digitalWrite(PIN_LED2, LOW);
        digitalWrite(PIN_LED3, HIGH);
        break;
      case 4: // Apenas o quarto LED aceso
        digitalWrite(PIN_LED3, LOW);
        digitalWrite(PIN_LED4, HIGH);
        break;
      case 5: // Todos os leds apagados
        digitalWrite(PIN_LED4, LOW);
        pushCounter = 0; // Reinicia o contador
        break;
    }
  }

  return EXIT_SUCCESS;
}