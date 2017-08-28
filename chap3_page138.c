#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
}*LinkedList, Node;


Node* find_reversed_n_node(LinkedList L, int n);
void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
void insert_element(LinkedList L, int value);

int main()
{//reverse right half elements of a linked list

	LinkedList L;
	Node* node;
	int n=3;
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

	node = find_reversed_n_node(L, n);
	if(node != NULL){
		printf("The reversed %dth element is: %d\n", n, node->value);
	} else {
		printf("%dth element is out of list scope\n", n);
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


Node* find_reversed_n_node(LinkedList L, int n){

	Node *p, *q;
	int len = 0, middle=0;
	int count = 0;
	p = L;
	q = L;

	while(q != NULL){
		if(count < n){
			q =  q->next;
			count++;
		} else {
			p = p->next;
			q = q->next;
		}
	}

	// arrive at the end of the list.
	if(p == L){
		return NULL;
	}
	return p;
}
/*
 * output:
linked list is:
6	5	4	3	2	1
7th element is out of list scope

linked list is:
6	5	4	3	2	1
The reversed 3th element is: 3
 * */
