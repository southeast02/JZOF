#include <stdio.h>
#include <stdlib.h>

int is_binary_search_tree(int arr[], int n);


int main(){
	int *arr;
	int n;
	int result;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}

	result = is_binary_search_tree(arr, n);
	if(result){
		printf("It is a binary tree\n");
	} else{
		printf("It is NOT a binary tree\n");
	}

}


int is_binary_search_tree(int arr[], int n){
	int left_sum = 0, right_sum=0;
	int left, right;
	int i=0;
	int flag = 0;
	int root_value;

	if(n <= 0) return 0;
	if(n == 1) return 1;

	root_value = arr[n-1];
	while(arr[i] < root_value){
		left_sum++;
		i++;
	}

	while(i < n-1){
		if( arr[i] < root_value){
			flag = 1;
			break;
		}
		i++;
	}

	if(flag == 1) return 0;
	right_sum = n - 1 - left_sum;

	left = 0;
	if(left_sum > 0)
		left = is_binary_search_tree(arr, left_sum);

	right = 0;
	if(left && right_sum > 0)
		right = is_binary_search_tree(arr+left_sum, right_sum);
	// use left and right to point out what's will be returned.
	return (left && right);
}

/**
 * output

7
5 7 6 9 11 10 8
It is a binary tree


4
7 4 6 5
It is NOT a binary tree


3
5 7 6
It is a binary tree
 * */
