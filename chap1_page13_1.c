/*
 1.what's the problem?
  求链表中倒数第k个节点

 2.how to deal with it?
   1.p指针先走k-1步,
   2.然后q指针从头开始
   3.p到 末尾,q则指向倒数第k个节点

   问题:
   1,k大于链表长度
   2,k为0
 */

#include <stdio.h>
#include <string.h>

#define N 100

typedef struct Node{
	int key;
	struct Node *next;
} Node, * LinkedList;

void initialize_linked_list(LinkedList*  L);
void insert_element(LinkedList L, int element_num);
void show_linked_list(LinkedList L);
LinkedList get_reversed_k_th_element(LinkedList L, int k);

int main(){
	LinkedList L;
	Node *p;

	int k1 = 2;
    int k2 = 0;

    initialize_linked_list(&L);
	insert_element(L, 6);
	show_linked_list(L);
	p = get_reversed_k_th_element(L, k1);

	if(p){
		printf("\nreversed %dth element is %d\n", k1, p->key);
	}

	p = get_reversed_k_th_element(L, k2);

	if(p){
		printf("\nreversed %dth element is %d\n", k2, p->key);
	}

}

void initialize_linked_list(LinkedList* L){
	*L = (Node*)malloc(sizeof(Node));

	if (L == NULL){
		printf("initialization failed");
		return;
	}
	(*L)->next = NULL;
}

void insert_element(LinkedList L, int element_num){
	if (!L){
		printf("list needs initialization.\n");
		return ;
	}
	LinkedList pre = L;
	LinkedList p = L;

	while(p->next != NULL){
		pre = p;
		p = p->next;
	}

	p = pre;

	for(int i = 0; i < element_num; i++){
		Node * node = (Node *)malloc(sizeof(Node));
		p->next = node;
		p->next->next = NULL;

		p->key = i + 1;
		p = p->next;
	}
}

void show_linked_list(LinkedList L){
	LinkedList p = L;

	if (!L){
		printf("empty list");
		return;
	}
	while(p->next != NULL){
		printf("%d\t", p->key);
		p = p->next;
	}
	printf("\n");
}

LinkedList get_reversed_k_th_element(LinkedList L, int k){
    LinkedList p, q;
    int i  = 0;

    p = q = L;

    if(k == 0){
    	printf("position is invalid, it shouldn't be 0\n");
    	return NULL;
    }

    while (p->next != NULL){
    	if(i < k){
    		p = p->next;
    	} else{
    		p = p->next;
    		q = q->next;
    	}
    	i++;
    }

    if (i < k){
    	printf("list length is %d, it's shorter than %d!\n", i,  k);
    	return NULL;
    }

    return q;
}
