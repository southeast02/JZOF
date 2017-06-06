#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>


using namespace std;


typedef struct Node {
	int value;
	struct Node *next;
}* LinkedList, LNode;


void insert_element(LinkedList L, int value);
void reverse_show_linked_list(LinkedList L);
void reverse_show_linked_list_2(LinkedList L);
void init_linked_list(LinkedList *L);


int main(){

	LinkedList L;
	init_linked_list(&L);
	insert_element(L, 2);
	insert_element(L, 3);
	insert_element(L, 34);

	//reverse_show_linked_list(L);
	reverse_show_linked_list_2(L);

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


void reverse_show_linked_list(LinkedList L){

	stack<LNode> stack1;
	LNode node;

	while(L->next != NULL){
		L = L->next; // skip the head node
		stack1.push(*L);
	}

	while(!stack1.empty()){
		node = stack1.top(); // rather than node = stack1.pop()
		cout << node.value << '\t';
		stack1.pop();
	}
}

void reverse_show_linked_list_2(LinkedList L){

	if(L->next){
		L = L->next;
		reverse_show_linked_list_2(L);
		cout << L->value << "\t";
	}
}

void init_linked_list(LinkedList *L){

	*L = (LNode *)malloc(sizeof(LNode));

	(*L)->next = NULL;
}

/**
 * output:
 * 34	3	2
 * */
