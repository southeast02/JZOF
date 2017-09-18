#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
	struct Node * sibling;
}*LinkedList, Node;


LinkedList clone(const LinkedList L1);
void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
Node* insert_element(LinkedList L, int value);


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

	L2 = clone(L1);
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


LinkedList clone(const LinkedList L1){
	LinkedList L2;
	Node *p1, *p2, *p2_head;
	Node *nodei, *nodej, *nodei_sibling;

	init_linkedlist(&L2);
	p2_head = L2;
	p1 = L1;

	// clone next field of list
	while(p1->next != NULL){
		p1 = p1->next;
		p2 = (Node *)malloc(sizeof(Node));
		p2->next = NULL;
		p2->sibling = NULL;
		p2->value = p1->value;
		p2_head->next = p2;
		p2_head = p2;
	}

	// clone sibling field of list
	p1 = L1;
	p2 = L2;
	while(p1->next != NULL){
		p1 = p1->next;
		p2 = p2->next;

		if(p1->sibling != NULL){
			nodei = L1;
			nodej = L2;
			nodei_sibling = p1->sibling;
			while(nodei->next != nodei_sibling){
				nodei = nodei->next;
				nodej = nodej->next;
			}
			p2->sibling = nodej->next;
		}
	}
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
