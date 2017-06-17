#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
}*LinkedList, Node;


LinkedList reversed_list(LinkedList L);
void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
void insert_element(LinkedList L, int value);

int main()
{//reverse right half elements of a linked list

	LinkedList L;
	init_linkedlist(&L);
	insert_element(L, 10);
	insert_element(L, 4);
	insert_element(L, 7);
	insert_element(L, 6);
	insert_element(L, 3);
	insert_element(L, 1);

	printf("linked list is:\n");
	show_linkedlist(L);

	printf("\n\nafter reverse:\n");
	//reverse list
	reversed_list(L);
	show_linkedlist(L);

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


LinkedList reversed_list(LinkedList L){

	Node *pre, *p;
	int len = 0, middle=0;

	pre = p = L;
	while(p->next){
		len++;
		pre = p;
		p = p->next;
	}

	if(len%2 == 0){
		middle = len/2 + 1;
	} else{
		middle = (len+1)/2;
	}
	pre = p = L;
	for(int i=0; i<middle; i++){
		pre = p;
		p = p->next;
	}

	Node *q = p->next;
	Node *qnext = q;

	while(q){
		qnext = q->next;
		q->next = p;
		p = q;
		q = qnext;
	}

	pre->next->next = NULL;
	pre->next = p;

	return L;
}
/*
 * output:

linked list is:
1	3	6	7	4	10	

after reverse:
1	3	6	10	4	7
 * */
