# Repositório de Códigos - Sistemas Microcomputadorizados - UNESP

Bem-vindo ao meu repositório de códigos! Este espaço foi criado para armazenar e compartilhar os códigos desenvolvidos durante as aulas práticas da disciplina de Sistemas Microcomputadorizados, parte do currículo do 5° ano do curso de Engenharia Elétrica da UNESP.

## Criando e Executando Arquivos C no VS Code com WSL

Este guia irá te mostrar como configurar o VS Code e o WSL para criar e executar arquivos C de forma eficiente.

### Pré-requisitos

* **WSL Instalado:** Certifique-se de que o WSL esteja instalado e configurado com sua distribuição Linux preferida.
* **VS Code Instalado:** Baixe e instale o VS Code a partir do site oficial.
* **Extensões do VS Code:**
    * "Remote - WSL" da Microsoft.
    * "C/C++" da Microsoft.

### Configuração

1.  **Instale as Ferramentas de Desenvolvimento C no WSL:**
    * Abra o terminal da sua distribuição WSL.
    * Execute os seguintes comandos:
        ```bash
        sudo apt update
        sudo apt install build-essential gdb
        ```
        * Isso instala o compilador GCC e o depurador GDB.

2.  **Abra o VS Code no Modo WSL:**
    * Abra o VS Code.
    * Clique no ícone "Remote Explorer" no canto inferior esquerdo.
    * Selecione "WSL: Nova Janela".
    * O VS Code será aberto conectado ao seu WSL.

## Criando um Arquivo C

1.  **Crie um Novo Arquivo:**
    * No VS Code, abra a pasta onde você deseja criar seu projeto C.
    * Crie um novo arquivo com a extensão ".c" (por exemplo, "meu\_programa.c").
    * Escreva seu código C no arquivo. Exemplo:
        ```c
        #include <stdio.h>

        int main() {
            printf("Olá, mundo do C no WSL!\n");
            return 0;
        }
        ```

2.  **Salve o Arquivo:**
    * Salve o arquivo (Ctrl+S).

## Compilando e Executando o Arquivo C

1.  **Abra o Terminal Integrado:**
    * No VS Code, vá para "Terminal" > "Novo Terminal".
    * O terminal será aberto dentro do seu ambiente WSL.

2.  **Compile o Código:**
    * No terminal, use o GCC para compilar seu código:
        ```bash
        gcc meu_programa.c -o meu_programa
        ```
        * Isso cria um arquivo executável chamado "meu\_programa".

3.  **Execute o Programa:**
    * No terminal, execute o programa:
        ```bash
        ./meu_programa
        ```
    * Você verá a saída do seu programa no terminal.

