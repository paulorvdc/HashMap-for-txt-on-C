#include <stdio.h>
#include <stdlib.h>
#include "listcad.h"
#include "table.h"
#define CLASS 127

int main() {
	linked_list *l[CLASS], **v[CLASS];
	//criacao do vetor de linked_lists
	for (int i = 0 ; i < CLASS ; i++) {
		l[i] = new_linked_list(-1);
	}
	for (int i = 0 ; i < CLASS ; i++) {
		v[i] = &l[i];
	}
	texto(*v,CLASS);
	printf("Hash map do .txt\nEm ordem de quantidade de repeticoes da palavra decrescente:\n\n");
	print_hash(*v,CLASS);
	destroy_hash(v, CLASS);
	return 0;
}