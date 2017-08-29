#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
}*LinkedList, Node;


void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
void insert_element(LinkedList L, int value);
LinkedList* merge_list(LinkedList L1, LinkedList L2);

int main()
{

	LinkedList L1, L2;
	LinkedList L;

	init_linkedlist(&L1);
	init_linkedlist(&L2);

	insert_element(L1, 12);
	insert_element(L1, 7);
	insert_element(L1, 1);

	insert_element(L2, 23);
	insert_element(L2, 6);
	insert_element(L2, 4);

	printf("linked list 1 is:\n");
	show_linkedlist(L1);
	puts("");

	printf("linked list 2 is:\n");
	show_linkedlist(L2);
	puts("");

	L = merge_list(L1, L2);
	printf("linked list after merged is:\n");
	show_linkedlist(L);
	puts("");

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


LinkedList* merge_list(LinkedList L1, LinkedList L2){
	Node* H;
	Node *p;
	Node *q;

	H = L1;
	if(L1->next == NULL){
		H = L2;
		return H;
	}
	if(L2->next == NULL){
		return H;
	}

	p = L1->next;
	q = L2->next;
	while(p!=NULL && q!=NULL){
		if(p->value <= q->value){
			H->next = p;
			p = p->next;
		} else{
			H->next = q;
			q = q->next;
		}
		H = H->next;
	}

	if(p!=NULL){
		H->next = p;
	}
	if(q!=NULL){
		H->next = q;
	}
	return L1;
}

/*
 * output:
linked list 1 is:
1	7	12
linked list 2 is:
4	6	23
linked list after merged is:
1	4	6	7	12	23


linked list 1 is:
1	7	12
linked list 2 is:

linked list after merged is:
1	7	12

linked list 1 is:

linked list 2 is:

linked list after merged is:

 * */
