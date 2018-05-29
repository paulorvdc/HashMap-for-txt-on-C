#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "listcad.h"

#define V 46

linked_list *new_linked_list(int size) {
	linked_list *l = (linked_list*) malloc(sizeof(linked_list));
	l->count = 0;
	l->max = size;
	l->first = NULL;

	return l;
}

int is_empty(linked_list *l) {
	return l->first == NULL;
}

int is_full(linked_list *l) {
	return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

void insert_first(char x[46], linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *aux = search(x,l);

	if (aux == NULL) {
		node *new_node = create_node(x);
		if(is_empty(l)) {
			l->first = new_node;
		} else {
			new_node->next = l->first;
			l->first = new_node;
		}
		l->count++;
	}
	else
		aux->c++;
}

node *create_node(char x[46]) {
	node *new_node = (node*) malloc(sizeof(node));
	for (int i = 0; i < V; i++) {
		if (x[i] == ',' || x[i] == '.' || x[i] == ')' || x[i] == ':' || x[i] == ';') {
			new_node->value[i] = ' ';
		}
		else if (x[i] == '(')
			new_node->c = 1;
		else
			new_node->value[i] = tolower(x[i]);
	}
	new_node->c = 1; 
	new_node->next = NULL;
	return new_node;
}

void print(linked_list *l) {
	if (l == NULL || is_empty(l))
		return;
	
	node *aux = l->first;
	printf("\nBegin:\n");
	while(aux != NULL) {
		for (int i = 0; i < V; i++) {
			if (aux->value[i] == ' ')
				break;
			printf("%c", aux->value[i]);	
		} 
		printf(", %d\n", aux->c);
		aux=aux->next;
	}
	printf("\nEnd.\n");
}

void destroy_linked_list(linked_list **l) {
	if (is_empty(*l)) return;

	node *aux = (*l)->first;
	while(aux != NULL) {
		node *del = aux;
		aux=aux->next;
		free(del);
	}
	free(*l);
	*l = NULL;
}

char *remove_first(linked_list *l) {
	if (l == NULL || is_empty(l))
		return "error";
	node *aux = l->first;
	char *x = aux->value;
	l->first = aux->next;
	free(aux);
	l->count--;
	return x;
}

void insert_last(char x[46], linked_list *l) {
	if(l == NULL || is_full(l)) return;
	node *new_node = create_node(x);
	if(is_empty(l)) {
		l->first = new_node;
	} else {
		node *aux = l->first;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = new_node;
	}
	l->count++;	
}

char *remove_last(linked_list *l) {
	if (l == NULL || is_empty(l))
		return "error";
	node *aux = l->first;
	while (aux->next->next != NULL) {
			aux = aux->next;
	}
	node *del = aux->next;
	char *x = del->value;
	aux->next = NULL;
	free(del);
	l->count--;
	return x;
}

void remove_value(char x[46], linked_list *l) {
	if (l == NULL || is_empty(l))
		return;
	node *aux = l->first;
	if (aux->value == x)
		remove_first(l);
	else {
		while((aux->next->value != x) && (aux->next != NULL)) {
			aux = aux->next;
		}
		if (aux->next != NULL) {
			node *del = aux->next;
			aux->next = del->next;
			free(del);
			l->count--;
		}
	}
}

void insert_at(char x[46], int i, linked_list *l) {
	if (is_full(l) || l == NULL) return;
	if (i > l->count) return;
	if (i == 0) {
		insert_first(x,l);
		return;
	}
	if (i == l->count) {
		insert_last(x,l);
		return;
	}
	node *new_node = create_node(x);
	node *aux = l->first;
	for (int j=0 ; j < (i-1) ; j++)
		aux = aux->next;
	new_node->next = aux->next;
	aux->next = new_node;
	l->count++;
}

node *search(char x[46], linked_list *l) {
	if (l == NULL || is_empty(l))
		return NULL;

	node *aux = l->first;
	int ver = 0;

	for (int i = 0; i < V; i++) {
		if (aux->value[i] == x[i])
			ver = 1;
		else {
			ver = 0;
			break;
		}
	}
	if (ver == 1)
		return aux;
	else 
		return NULL;
}