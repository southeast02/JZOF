#include <stdio.h>
#include <stdlib.h>

unsigned int find_first_bit_is_1(int num);
void find_two_nums_apper_once(int arr[], int n, int* num1, int *num2);
int is_bit_1(int num, int index_of_1);


int main(){
	int *arr;
	int n;
	int num1, num2;
	scanf("%d", &n);
	if((n & 1) == 1){
		printf("Total elements must be even.\n");
	} else if ( n < 1){
		printf("Total elements must be a positive number.\n");
	}
	arr = (int *)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}

	find_two_nums_apper_once(arr, n, &num1, &num2);
	printf("The two elements are %d, %d\n", num1, num2);

}


void find_two_nums_apper_once(int arr[], int n, int* num1, int *num2){
	if(n < 2){
		return;
	}

	// get num1^num2, the result is in result_exclusive_or
	int result_exclusive_or = 0;
	for(int i=0; i < n; i++){
		result_exclusive_or ^= arr[i];
	}

	// find index of 1, which appears first times in right hand
	unsigned int  index_of_1 = find_first_bit_is_1(result_exclusive_or);

	// find num1 and num2
	*num1 = *num2 = 0;
	for(int i=0; i < n; i++){
		if(is_bit_1(arr[i], index_of_1)){
			*num1 ^= arr[i];
		} else {
			*num2 ^= arr[i];
		}
	}
}

unsigned int find_first_bit_is_1(int num){
	unsigned int index_bit=0;

	while( ((num & 1) == 0) && (index_bit < 32)){
		num = num >> 1;
		index_bit++;
	}
	return index_bit;
}

int is_bit_1(int num, int index_of_1){
	num = num >> index_of_1;

	return (num & 1);
}

/**
 * output
 *
 4
2 3 4 4
The two elements are 3, 2

2
1 2
The two elements are 1, 2

 * */
