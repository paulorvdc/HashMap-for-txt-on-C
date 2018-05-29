#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listcad.h"
#include "table.h"
#define V 46

int espalhar(int x, int i) {
	return x % i;
}

void insert_hash(linked_list **v, char y[46], int classes) {
	int i = espalhar(valor_palavra(y), classes);
	insert_first(y, v[i]);
}

node *search_hash(linked_list **v, char y[46], int classes) {
	int i = espalhar(valor_palavra(y), classes);
	return search(y, v[i]);
}

void destroy_hash(linked_list ***v, int classes) {
	for (int i = 0; i < classes; i++) {
		destroy_linked_list(v[i]);
	}
}

int valor_palavra(char p[46]) {
	int word = 0;
	for (int i = 0; i < V; i++) {
		if (p[i] == ' ')
			return word;
		word += (int) p[i];
	}
	return word;
}

void print_hash(linked_list **v, int classes) {
	int co = 0;
	for (int i = 0; i < classes; i++) {
		co += v[i]->count;
	}
	node **array = malloc(sizeof(node) * co);
	node *aux;
	int j = 0;
	for (int i = 0; i < classes; i++) {
		aux = v[i]->first;
		while (aux != NULL) {
			array[j] = aux;
			aux = aux->next;
			j++;
		}
	}
	bubbleSort(array, co);
	for (int j = 0; j < co; j++) {
		for (int i = 0; i < V; i++) {
			if (array[j]->value[i] == ' ')
				break;
			printf("%c", array[j]->value[i]);	
		} 
		printf(", %d\n", array[j]->c);
	}
	free(array);
	array = NULL;
}

void bubbleSort(node **vetor, int tam) {
    for (int fim = tam-1; fim > 0; --fim) {
        for (int i = 0; i < fim; ++i) {
            if (vetor[i]->c < vetor[i+1]->c) {
                node *aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}


int texto (linked_list **v,int classes) {
	char c;
	FILE *fp;
	int count = 0;
	int flag = 0;
	char s[100];
	int si = 0;
	node *aux;

	for (int i = 0; i < V; i++) {
		s[i] = ' ';
	}

	if ((fp = fopen("Teste1.txt", "r")) == NULL) {
		printf("DEU ERRO");
		exit(1);
	}

	while(!feof(fp)) {
		c = getc(fp);

		s[si] = c;

		if (c == ' ' || c == '\n') {
			if (flag == 0) {
				count++;
				flag = 1;

				insert_hash(v,s,classes);
				
				for (int i = 0; i < V; i++) {
					s[i] = ' ';
				}
				si = 0;
			}
		}
		else {
			si++;
			if ( flag == 1 )
				flag = 0;
		}

		/*str2[i]=c;
		 * str2=(char*)malloc(MAX*sizeof(int));*/
	}
	fclose(fp);
	return count;
}