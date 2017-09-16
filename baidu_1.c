#include <stdio.h>
#include <stdlib.h>

int find_single_times_element(int arr[], int n);


int main(){
	int *arr;
	int n;
	int result;

	scanf("%d", &n);
	if((n & 1) == 0){
		printf("Total elements must be odd.\n");
	} else if ( n < 1){
		printf("Total elements must be a positive number.\n");
	}
	arr = (int *)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}

	result = find_single_times_element(arr, n);
	printf("Single element is %d\n", result);

}


int find_single_times_element(int arr[], int n){
	int result =  arr[0];

	for(int i=1; i < n; i++){
		result ^= arr[i];
	}
	return result;
}

/**
 * output
5
1 2 2 1 3
Single element is 3
 * */
