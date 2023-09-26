
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1004

void reversor3000(char saida[]) {//essa função inverte a string saida, uma vez que ela é formada de trás para frente
    int tam_saida = strlen(saida);
    for (int i = 0, j = tam_saida - 1; i < j; i++, j--) {//realiza a troca digito a digito
        char temporario = saida[i];
        saida[i] = saida[j];
        saida[j] = temporario;
    }
}

// Função de soma
void adicao(char a[], char b[], char saida[]) {
    int num_a, num_b; // variavel que vai receber cada dígito da string
    int carry = 0; // carrega o dígito da dezena da soma
    int tam_a = strlen(a); // leitura do tamanho da string
    int tam_b = strlen(b);
    int tam; // tamanho da string de saida

    if (tam_a > tam_b) { // condição para descobrir qual string tem tamanho maior
        tam = tam_a;
    } else {
        tam = tam_b;
    }

    for (int i = 0; i < tam; i++) { // fará a leitura, dígito a dígito
        if (i < tam_a) {
            num_a = a[tam_a - i - 1] - '0'; //converte dígito (char) em inteiro (int)
        } else {
            num_a = 0;//adiciona 0 para completar o tamamnho da string quando esta for menor que aquela
        }
        if (i < tam_b) {
            num_b = b[tam_b - i - 1] - '0';
        } else {
            num_b = 0;
        }
        int som = num_a + num_b + carry; // soma dos dígitos
        carry = som / 10; // tira o dígito da dezena e passa para a próxima interação
        saida[i] = (som % 10) + '0'; // finaliza o dígito
    }

    if (carry > 0) { // caso ao fim sobre algo no carry, será concatenado no final da resposta
        saida[tam] = carry + '0';
        saida[tam + 1] = '\0'; // adiciona +1 ao tamanho da resposta para o \0 que encerra a string
    } else {
        saida[tam] = '\0'; // define o último dígito como nulo
    }

    // reverte a string
    reversor3000(saida);
}

// Função de subtração
void subtracao(char a[], char b[], char saida[]) {
    int num_a, num_b;
    int carry = 0;
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    int tam;

    if (tam_a > tam_b) {
        tam = tam_a;
    } else {
        tam = tam_b;
    }

    int negativo = 0;

    if (tam_a < tam_b || (tam_a == tam_b && strcmp(a, b) < 0)) {//troca 'a' por 'b' quando a subtração for negativa, strcmp compara os valores de 'a' e 'b' na tabela ascii
        char temporario[TAM];
        strcpy(temporario, a);//realiza a troca da string 'a' por 'b' para realizar a subtração corretamente, tendo que colocar 'a' em uma var temporária antes
        strcpy(a, b);
        strcpy(b, temporario);

        int temporario_tam = tam_a;//troca o tamanho das duas strings
        tam_a = tam_b;
        tam_b = temporario_tam;

        negativo = 1;
    }

    for (int i = 0; i < tam; i++) { //laço faz a subtração digito a digito
        if (i < tam_a) {
            num_a = a[tam_a - i - 1] - '0';//converte dígito (char) em inteiro (int).
        } else {
            num_a = 0;
        }
        if (i < tam_b) {
            num_b = b[tam_b - i - 1] - '0';
        } else {
            num_b = 0;
        }
        int subtracao = num_a - num_b - carry;

        if (subtracao < 0) {// quando a subtração resulta em negativo
            subtracao += 10;//adiciona 10 para ajustar o resultado
            carry = 1;//define carry como 1 para a próxima iteração
        } else {
            carry = 0;//nada muda
        }

        saida[i] = subtracao + '0';
    }
    // Verifique se o ultimo digito de saida é zero
    while (tam > 1 && saida[tam - 1] == '0') {
        saida[tam - 1] = '\0'; // Define o ultimo digito como nulo
        tam--;//Decrementa o valor de tam em 1
    }

    if (negativo == 1) {
        saida[tam] = '-';//concatena o sinal negativo quando necessário
        saida[tam + 1] = '\0';//adiciona 1 de espaço no tamanho para o \0 que encerra a string
    } else {
        saida[tam] = '\0'; //define o ultimo digito como nulo
    }

    // reverte a string
    reversor3000(saida);
}

// Função de multiplicação
void multiplicacao(char a[], char b[], char saida[]) {
    int tam_a = strlen(a);
    int tam_b = strlen(b);
    int tam = tam_a + tam_b;

    for (int i = 0; i < tam_a + tam_b; i++) {
        saida[i] = '0';
    }
    saida[tam_a + tam_b] = '\0';

    for (int i = 0; i < tam_a; i++) {
        int num_a = a[tam_a - i - 1] - '0';
        int carry = 0;

        for (int j = 0; j < tam_b; j++) {
            int num_b = b[tam_b - j - 1] - '0';
            int total = (saida[i + j] - '0') + num_a * num_b + carry;
            carry = total / 10;
            saida[i + j] = (total % 10) + '0';
        }

        if (carry > 0) {
            saida[i + tam_b] += carry;
        }
    }

    // reverte a string
    reversor3000(saida);
}

int main() {
    int n, o;
    int hunter = 0;//hunter é um caçador de zeros que ignora zeros irrelevantes do resultado(saida) que podem aparecer à esquerda
    char a[TAM], b[TAM], saida[TAM];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", a, b, &o);//entrada

        if (o == 1) {
            adicao(a, b, saida);//dados que vão para o void
        } else if (o == 2) {
            subtracao(a, b, saida);
        } else if (o == 3) {
            multiplicacao(a, b, saida);
        }

         //remove zeros  que podem aparecer no inicio do saida
        while (saida[hunter] == '0' && saida[hunter + 1] != '\0') {
            hunter++;
        }

        printf("%s\n", &saida[hunter]);
        hunter = 0; // Reseta hunter para a próxima inteiração
    }
    return 0;
}
