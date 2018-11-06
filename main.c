/*
 *
 *
 * Version: Dev 0.0.1
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define size 10

//Data Structure
int array[size];

//Data Variables
int top = -1;
int front = -1, rear = -1;

//Insert LIFO
void push(int item) {
	if (top >= size - 1) {
		printf("\nA pilha está cheia! Não é possível inserir valor!\n");
	} else {
		top++;
		array[top] = item;
		printf("\nItem inserido com sucesso!\n");
	}
}

//Remove LIFO
int pop() {
	if (top < 0) {
		printf("\nA pilha está vazia! Não há valor para remover!\n");
	} else {
		int item;
		item = array[top];
		top--;
		printf("\nItem removido com sucesso!\n");
		return item;
	}
}

//Insert FIFO
void put(int item) {
	if (rear == size-1) {
		printf("\nFila cheia! Impossível inserir valores!\n");
	} else {
		if (front == -1) {
			front = 0;
		}
		rear++;
		array[rear] = item;
		printf("\nO valor %d foi inserido com sucesso!\n", item);
	}
}

//Remove FIFO
int get() {
	int value;
	if (front > rear) {
		printf("\nFila vazia! Impossível remover valores!\n");
	} else {
		value = array[front];
		front++;
		if (front > rear)		 {
			front = rear = -1;
		}
	}
	return value;
}

//Display array
void imprimir() {
	if (rear == -1) {
		printf("\nFila vazia! Impossível imprimir valores!\n");
	} else {
		int i;
		printf("\nValores da Fila\n|");
		for (i = front; i <= rear; i++) {
			printf(" %d |", array[i]);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opt, value;
	while (1) {
		system("cls");
		printf("MENU - FIFO/LIFO\n\n");
		printf("\tLIFO - Inserir valor [1]\n");
		printf("\tLIFO - Remover valor [2]\n");
		printf("\tFIFO - Inserir valor [3]\n");
		printf("\tFIFO - Remover valor [4]\n");
		printf("\tImprimir vetor       [5]\n");
		printf("\tSair                 [0]\n");
		printf("Digite a opção: ");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				printf("\tDigite o valor: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				value = pop();
				printf("O valor removido foi %d\n", value);
				break;
			case 3:
				printf("\tDigite o valor: ");
				scanf("%d", &value);
				put(value);
				break;
			case 4:
				value = get();
				printf("\nO valor %d foi removido com sucesso!\n", value);
				break;
			case 5:
				imprimir();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nOpção Inválida!\n");
		}
		system("pause");
	}
	system("pause");
	return 0;
}
