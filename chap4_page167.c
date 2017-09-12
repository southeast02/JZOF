#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct {
	int value;
	int min_value;
}Number;

typedef struct {
	Number arr[N];
	int top;
}stack;

void push(stack* s, int value);
int pop(stack* s);
int is_stack_full(const stack * s);
int is_stack_empty(const stack * s);
int min(const stack* s);

int main(){
	stack s;
	int value;

	// initialize stack 's'
	s.top=0;

	// fill some value to stack 's'
	push(&s, 2);
	push(&s, 3);
	push(&s, 7);
	push(&s, 1);
	push(&s, 1);

	while(!is_stack_empty(&s)){
		value = pop(&s);
		printf("pop value: %d", value);
		if(!is_stack_empty(&s)){
			printf("\tafter pop a value, current min value: %d\n", min(&s));
		}
	}

}


void push(stack* s, int value){
	if(is_stack_full(s))
		return;
	if(is_stack_empty(s)){
		s->arr[s->top].value = value;
		s->arr[s->top].min_value = value;
		s->top++;
	} else{
		s->arr[s->top].value = value;

		int min_value = min(s);
		if(min_value < value){
			s->arr[s->top].min_value = min_value;
		}else {
			s->arr[s->top].min_value = value;
		}
		s->top++;
	}
}


int pop(stack* s){
	if(is_stack_empty(s)){
		return -1;
	}
	s->top--;
	return s->arr[s->top].value;
}

int is_stack_full(const stack * s){
	return s->top == N;
}

int is_stack_empty(const stack * s){
	return s->top == 0;
}

int min(const stack* s){
	if(is_stack_empty(s)){
		return -1;
	}
	return s->arr[s->top-1].min_value;
}

/**
* output:
*
pop value: 1	after pop a value, current min value: 2
pop value: 7	after pop a value, current min value: 2
pop value: 3	after pop a value, current min value: 2
pop value: 2

 * */
