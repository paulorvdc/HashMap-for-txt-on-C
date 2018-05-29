#ifndef TABLE_H
#define TABLE_H

int espalhar(int x, int i);
void insert_hash(linked_list **v, char y[100], int classes);
node *search_hash(linked_list **v, char y[100], int classes);
void destroy_hash(linked_list ***v, int classes);
int valor_palavra(char p[100]);
void print_hash(linked_list **v, int classes);
void bubbleSort(node **vetor, int tam);
int texto(linked_list **v, int classes);

#endif