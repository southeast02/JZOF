#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int value;
	struct Node *next;
}* LinkedList, LNode;


void insert_element(LinkedList L, int value);
void show_linked_list(LinkedList L);
void init_linked_list(LinkedList *L);
void delete_element(LinkedList L, int value);


int main(){

	LinkedList L;

	init_linked_list(&L);
	insert_element(L, 3);
	insert_element(L, 4);
	insert_element(L, 4);
	show_linked_list(L);

	puts("\n");
	delete_element(L, 4);
	delete_element(L, 5);
	show_linked_list(L);

	return 0;
}


void insert_element(LinkedList L, int value){
	LNode * node = (LNode *) malloc(sizeof(LNode));
	node->value = value;
	node->next = NULL;

	if(L->next == NULL){ // L is the head node in the list
		L->next = node;  // so we judge the L->next value for end flag
	} else {
		LNode *p = L;
		while(p->next != NULL){
			p = p->next;
		}

		p->next = node;
	}
}


void show_linked_list(LinkedList L){

	while(L->next != NULL){
		L = L->next; // skip the head node
		printf("%d\t", L->value);
	}
}

void init_linked_list(LinkedList *L){

	*L = (LNode *)malloc(sizeof(LNode));

	(*L)->next = NULL;
}


void delete_element(LinkedList L, int value){

	LNode *p = L;
	LNode *q = NULL;

	q = p;
	p = p->next;
	while(p != NULL){

		if(p->value == value){ // delete all same values in linked list
			free(p);           // free space
			q->next = p->next;
			p = p->next;
		} else {
			q = p;
			p = p->next;
		}
	}

}


/**
 * output:
 * 3	4	4
 * 3
 * */
