/******************************************************************************

Escreva um programa em C que receba os dados de consumo médio (km/l), tempo gasto numa
viagem (hora) e a velocidade média (km/h) de um automóvel, e calcule a distância percorrida
(km) e a quantidade de combustível (litros) utilizada pelo automóvel. Os dados devem ser
passados ao programa na forma de argumentos no momento da execução. Não deve ser utilizada
a função scanf ou similares. Ao final, o programa deve exibir os resultados na tela.

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <consumo> <tempo> <velocidade>\n", argv[0]);
        return 1;
    }

    double consumo = atof(argv[1]);
    double tempo = atof(argv[2]);
    double velocidade = atof(argv[3]);

    double distancia = velocidade * tempo;
    double combustivel = distancia / consumo;

    printf("Consumo [km/L]: %.2f, Tempo [h]: %.2f, Velocidade [km/h]: %.2f\n", consumo, tempo, velocidade);
    printf("Distancia percorrida: %.2f km\n", distancia);
    printf("Combustivel utilizado: %.2f litros\n", combustivel);

    return 0;
}