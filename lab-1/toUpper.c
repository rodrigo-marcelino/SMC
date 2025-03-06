/*************************************************************************
    Escreva um programa que receba uma linha de texto e a armazene em um array do tipo char
    com, no máximo, 100 elementos. O programa deve transformar todas as letras da linha de
    texto em letras maiusculas e exibi-las na tela. Depois, deve transformar todas as letras da
    linha de texto em letras minúsculas e, também, exibi-las na tela. Utilize as funções tolower e
    toupper, definidas na biblioteca ctype.h.
************************************************************************************************/


#include <stdio.h>
#include <ctype.h>

int main() {
    
    char texto[100];  // Declara um array de caracteres com capacidade para 100 caracteres

    // Solicita ao usuário que insira um texto
    printf("Digite um texto (máximo de 100 caracteres): ");
    fgets(texto, sizeof(texto), stdin);

    /*
    texto[i] != '\0' é usada para verificar se o caractere atual no array texto é diferente do caractere nulo ('\0').
    Em C, strings são arrays de caracteres que terminam com um caractere nulo ('\0').
    */

    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        texto[i] = toupper(texto[i]);
    }

    
    // Imprime o texto inserido
    printf("\nVocê digitou: %s", texto);
    
    return 0;
}
