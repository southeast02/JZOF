#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
}*LinkedList, Node;


Node* find_middle_element(LinkedList L);
void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
void insert_element(LinkedList L, int value);

int main()
{//reverse right half elements of a linked list

	LinkedList L;
	Node* node;
	init_linkedlist(&L);
	insert_element(L, 1);
	insert_element(L, 2);
	insert_element(L, 3);
	insert_element(L, 4);
	insert_element(L, 5);
	insert_element(L, 6);

	printf("linked list is:\n");
	show_linkedlist(L);
	puts("");

	node = find_middle_element(L);
	if(node != NULL){
		printf("The middle element is %d\n", node->value);
	} else {
		printf("List is empty\n");
	}


}

void init_linkedlist(LinkedList* L){
	*L = (LinkedList)malloc(sizeof(Node));
	if(*L){
		(*L)->next = NULL;
	}
}

void insert_element(LinkedList L, int value){
	Node * p = (Node*)malloc(sizeof(Node));
	if(p){
		p->next = L->next;
		p->value = value;
		L->next = p;
	}
}
void show_linkedlist(LinkedList L){
	Node *p = L;
	while(p->next){
		p = p->next;
		printf("%d\t", p->value);
	}
}


Node* find_middle_element(LinkedList L){

	Node *p, *q;
	int count = 0;
	p = L;
	q = L;

	while(p != NULL){
		p = p->next;
		count ++;
		if((count & 0x1) == 0){
			q = q->next;
		}
	}

	// arrive at the end of the list.
	if(q == L){
		return NULL;
	}
	return q;
}
/*
 * output:
linked list is:
6	5	4	3	2	1
The middle element is 4

linked list is:
5	4	3	2	1
The middle element is 3


linked list is:

List is empty

 * */
