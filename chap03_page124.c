
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
void delete_dulication(LinkedList L);

int main()
{//deduplication

	LinkedList L;
	init_linkedlist(&L);
	insert_element(L, 10);
	insert_element(L, 4);
	insert_element(L, 4);

	printf("linked list is:\n");
	show_linkedlist(L);

	printf("\nafter deduplicate\n");
	delete_dulication(L);
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


void delete_dulication(LinkedList L){
	Node *pre = L;
	Node *p = L->next;
	int HASDUP = 0;

	while(p->next != NULL){
		while(p->next != NULL && p->value==p->next->value){
			p->next = p->next->next;
			if(HASDUP == 0){
				HASDUP = 1;
			}
		}
		if(HASDUP){
			pre->next = p->next;
			p = p->next;
		} else{
			pre = p;
			p = p->next;
		}
	}
}

/*
 * output:
linked list is:
4	4	10	
after deduplicate
10
 * */
