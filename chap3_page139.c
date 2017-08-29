#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node * next;
}*LinkedList, Node;


Node* linkedlist_has_loop(LinkedList L);
int number_of_nodes_in_loop(LinkedList L, Node *node);
Node* find_reversed_n_node(LinkedList L, int n);
Node * find_entry_point(LinkedList L);

void init_linkedlist(LinkedList* L);
void show_linkedlist(LinkedList L);
Node* insert_element(LinkedList L, int value);

int main()
{//reverse right half elements of a linked list

	LinkedList L;
	Node* node;
	Node *loop_start;
	Node *loop_end;

	init_linkedlist(&L);
	loop_end = insert_element(L, 1);
//	insert_element(L, 2);
//	loop_start = insert_element(L, 3);
//	insert_element(L, 4);
//	insert_element(L, 5);
//	insert_element(L, 6);
	loop_start = loop_end;
	loop_end->next = loop_start;

	printf("linked list is:\n");
	show_linkedlist(L);
	puts("");

	node = find_entry_point(L);
	if(node != NULL){
		printf("The entry point is %d\n", node->value);
	} else {
		printf("Linked list has no loop\n");
	}

	return 1;
}

void init_linkedlist(LinkedList* L){
	*L = (LinkedList)malloc(sizeof(Node));
	if(*L){
		(*L)->next = NULL;
	}
}


Node* insert_element(LinkedList L, int value){
	Node * p = (Node*)malloc(sizeof(Node));
	if(p){
		p->next = L->next;
		p->value = value;
		L->next = p;
	}
	return p;
}


void show_linkedlist(LinkedList L){
	Node *q;
	Node *p = L;

	q = linkedlist_has_loop(L);
	while(p->next != q){
		p = p->next;
		printf("%d\t", p->value);
	}
	if(q != NULL){
		p = p->next;
		printf("%d\t", p->value);
		while(p->next != q){
			p = p->next;
			printf("%d\t", p->value);
		}
	}

}


Node* linkedlist_has_loop(LinkedList L){
	Node *p;
	Node *q;
	int count;

	count = 1;
	p = L->next;
	q = L;

	while(p != NULL && !(p == q || p->next == q)){
		p = p->next;
		count ++;
		if((count &0x1) == 0){
			q = q->next;
		}
	}

	if(p == NULL){
		return NULL;
	}
	return q;
}

int number_of_nodes_in_loop(LinkedList L, Node *node){
	Node *p;
	Node *q;
	int count;

	p = node->next;
	q = node;
	count = 1;

	while(p != q){
		count++;
		p = p->next;
	}
	return count;
}


Node* find_reversed_n_node(LinkedList L, int n){

	Node *p, *q;
	int count = 1;

	p = L->next;
	q = L;

	while(p != q){
		if(count < n){
			p =  p->next;
			count++;
		} else {
			p = p->next;
			q = q->next;
		}
	}
	return p;
}

Node * find_entry_point(LinkedList L){
	Node *p;
	int num;

	p = linkedlist_has_loop(L);
	if(p == NULL){
		return NULL;
	}
	num = number_of_nodes_in_loop(L, p);
	p = find_reversed_n_node(L, num);
	return p;
}

/*
 * output:
linked list is:
6	5	4	3	2	1
Linked list has no loop


linked list is:
6	5	4	3	2	1
The entry point is 3

linked list is:
1
The entry point is 1

 * */
