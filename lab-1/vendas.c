/****************************************************************************************
3) Uma empresa realiza o pagamento de seus vendedores através de comissões por suas vendas
semanais. Cada vendedor recebe R$ 500,00 por semana mais 9% do valor de suas vendas
naquela semana. Por exemplo, se um vendedor faturou R$ 5000,00 em vendas em uma semana,
seu pagamento será R$ 500,00 + 9% de R$ 5000,00, o que equivale a R$ 950,00. Escreva um
programa em C que determine quantos vendedores receberam salários em cada uma das faixas
a seguir:
a) R$ 500,00 a R$ 599,00
b) R$ 600,00 a R$ 699,00
c) R$ 700,00 a R$ 799,00
Para tanto, crie o tipo de dados Vendedor, utilizando struct e typedef. Este tipo de dados
deve conter os campos nome e faturamento. Suponha que a empresa possui, pelo menos,
20 vendedores. Crie variáveis do tipo Vendedor para representar cada um dos vendedores e armazene-as em um array (do tipo Vendedor[]). Crie um segundo array (por exemplo, int
faixas[]) em que cada elemento represente uma das faixas salariais apresentadas acima.
Ao final do processamento, o programa deve apresentar na tela as faixas salariais e o número
de vendedores presentes em cada faixa.
*********************************************************************************************/
#include <stdio.h>

// Criando o tipo Vendedor: 
typedef struct {
    /* data */
    float salary;
    float sales;
    float totalIncome;
} Vendedor;

float calcIncome(float sales, float salary){
    return salary + sales * 0.09;
}

int main() {

    Vendedor employees[5];

    for(int i = 0; i < 5; i++){
        printf("");
    }

    return 0;
}