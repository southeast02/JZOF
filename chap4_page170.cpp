#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<stack>

using namespace std;

int is_stack_seq(int arr[], int n, int seq[]);

int main()
{
	int n;
	int *arr;
	int *seq;
	int result;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	seq = (int*)malloc(sizeof(int)*n);

	// data in stack
	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}

	// data in pop seqence
	for(int i=0; i<n; i++){
		scanf("%d", seq+i);
	}

	result = is_stack_seq(arr, n, seq);
	if(result == 1){
		printf("CORRECT");
	}else {
		printf("NOT STACK SEQENCE");
	}
}


int is_stack_seq(int arr[], int n, int seq[]){
	stack<int> s;
	int j=0;

	for(int i=0; i<n ; i++){
		s.push(arr[i]);
		while(!s.empty() && j < n && (s.top()== seq[j])){
			j++;
			s.pop();
		}
	}
	if(!s.empty()){
		return 0;
	}
	return 1;
}

/**
 * OUTPUT
 5
1 2 3 4 5
4 3 5 1 2
NOT STACK SEQENCE

5
1 2 3 4 5
4 5 3 2 1
CORRECT
 * */
