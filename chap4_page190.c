#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
	struct Node * sibling;
}*LinkedList, Node;


void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
Node* insert_element(LinkedList L, int value);
LinkedList clone2(LinkedList L1);
LinkedList reconnect_list(LinkedList L1);
void clone_siblings(LinkedList L);
void clone_nodes(LinkedList L);


int main()
{

	LinkedList L1;
	LinkedList L2;
	Node* node[5];

	init_linkedlist(&L1);

	node[4] = insert_element(L1, 5);
	node[3] = insert_element(L1, 4);
	node[2] = insert_element(L1, 3);
	node[1] = insert_element(L1, 2);
	node[0] = insert_element(L1, 1);

	node[0]->sibling = node[2];
	node[1]->sibling = node[4];
	node[3]->sibling = node[1];

	printf("linked list 1 is:\n");
	show_linkedlist(L1);

	L2 = clone2(L1);
	puts("\n\n=====================================");
	printf("Cloned list 2 is:\n");
	show_linkedlist(L2);
	puts("");


}


void init_linkedlist(LinkedList* L){
	*L = (LinkedList)malloc(sizeof(Node));
	if(*L){
		(*L)->next = NULL;
		(*L)->sibling = NULL;
	}
}


Node* insert_element(LinkedList L, int value){
	Node * p = (Node*)malloc(sizeof(Node));
	if(p){
		p->next = L->next;
		p->sibling = NULL;
		p->value = value;
		L->next = p;
	}
	return p;
}


void show_linkedlist(LinkedList L){
	Node *p = L;
	while(p->next){
		p = p->next;
		printf("%d", p->value);
		if(p->sibling != NULL)
			printf("(%d)\t", p->sibling->value);
		else
			printf("\t");
	}
}


void clone_nodes(LinkedList L){
	Node *p;
	Node *nodei;

	p = L;
	while(p->next != NULL){
		p = p->next;
		nodei = (Node*)malloc(sizeof(Node));
		nodei->value = p->value;
		nodei->sibling = NULL;
		nodei->next = p->next;
		p->next = nodei;
		p = nodei;
	}
}


void clone_siblings(LinkedList L){
	Node *p = L;
	while(p->next != NULL){
		p = p->next;
		if(p->sibling != NULL){
			p->next->sibling = p->sibling->next;
		}
		p = p->next;
	}
}


LinkedList reconnect_list(LinkedList L1){
	LinkedList L2;
	Node *p1, *p2;

	init_linkedlist(&L2);
	p1 = L1;
	if(L1->next == NULL){
		return L2;
	}

	p2 = L2;
	L2->next = L1->next->next;
	while(p1->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
		p1->next = p2->next;
		if(p2->next != NULL){
			p2->next = p1->next->next;
		}
	}
	return L2;
}


LinkedList clone2(LinkedList L1){
	LinkedList L2;

	clone_nodes(L1);
	clone_siblings(L1);
	L2 = reconnect_list(L1);
	return L2;
}


/*
 * output:
linked list 1 is:
1(3)	2(5)	3	4(2)	5

=====================================
Cloned list 2 is:
1(3)	2(5)	3	4(2)	5

 * */
