#ifndef LISTCAD_H
#define LISTCAD_H

typedef struct Node {
	char value[46];
	int c;
	struct Node *next;
} node;

typedef struct {
	node *first;
	int count;
	int max;
} linked_list;

linked_list *new_linked_list(int size);
int is_empty(linked_list *l);
int is_full(linked_list *l);
void insert_first(char x[46], linked_list *l);
node *create_node(char x[46]);
void print(linked_list *l);
void destroy_linked_list(linked_list **l);
char *remove_first(linked_list *l);
void insert_last(char x[46], linked_list *l);
char *remove_last(linked_list *l);
void remove_value(char x[46], linked_list *l);
void insert_at(char x[46], int i, linked_list *l);
node *search(char x[46], linked_list *l);

#endif