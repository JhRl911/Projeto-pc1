
# Projeto 1 - Aritmética

*Feito por*: João Henrique Rodrigues Lopes

*Matrícula*: 231057600020

## Introdução do projeto:

"A arimética é uma parte importante da matemática que lida com operação sobre
números. Neste projeto deverá ser implementado três operações básicas sobre inteiros:
- Adição.
- Subtração.
- Multiplicação.
Contudo, uma observação precisa ser feita: os inteiros podem ser arbitrariamente grandes!"

Logo, o objetivo do programa/projeto é realizar operações aritméticas com números de grande extensão (output de até 1000 dígitos com precisão), fazendo uso de strings.

## Restrições:
- 1 ≤ n ≤ 103
- 0 ≤ a, b ≤ 10^500
- 1 ≤ o ≤ 3.
- Nenhum número será informado com zeros à esquerda

## Compilação do Código:

### Pré-requisitos:
Será necessário o uso do GCC (GNU Compiler Collection). É possível ver o status do gcc com o comando no terminal:
```C
	gcc --version
```
Após, descompacte o arquivo joaoh_projeto1.zip

Localize o diretório onde o código-fonte foi baixado:
```C
	cd joaoh_projeto1-c
```
Compile o código com o GCC.
```C
	gcc joaoh_projeto1.c -o joaoh_projeto1
```
Execução:
Após a compilação bem-sucedida, você pode executar o programa da calculadora usando o seguinte comando:
```C
	./joaoh_projeto1
```
O programa solicitará entradas para a operação desejada e os números inteiros nos quais você deseja realizar a operação. Siga as instruções apresentadas na tela para usar a calculadora.

## Uso do programa:

A primeira entrada é a quantidade de vezes que o programa irá rodar.
Após, na mesma linha, será feita a entrada dos valores 'a' e 'b' em string e do valor 'o' em inteiro, sendo separadas por um espaço.  

Quando o = 1, será feita a adição de 'a' e 'b'; quando o = 2, será feita a subtração; quando o = 3, será feita a multiplicação.

## Exemplos de Uso
Aqui está um exemplos de uso da calculadora:

- Entrada:

7
1 1 1
1 2 2
10 10 3
127349847218943757471829 9942174127482147421798427421 1
127349847218943757471829 9942174127482147421798427421 3
1 1000 2
1234 1234567890123456789 2

- Saída:

2
-1
100
9942301477329366365555899250
1266134356158986930307618580257140119125290908623009
-999
-1234567890123455555
