#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10

void adjust_array(int *arr, int N, int (*func)(int));
int is_even(int num);

int main(){

	int arr[LEN] = {2, 4, 2, 1, 3, 3, 5, 7, 9, 11};

	adjust_array(arr, LEN, is_even);

	for(int i=0; i<LEN; i++){
		printf("%d\t", arr[i]);
	}
}

int is_even(int num){
	return (num & 1) == 0;
}

void adjust_array(int *arr, int N, int (*func)(int)){
	int low = 0;
	int high = N-1;
	int temp;

	while(low < high){
		// find arr[low]%2==0
		//while(low<high && low<N){
		// no need "low<N", high acts as upper bound
		while(low<high && !is_even(arr[low])){
			low++;
		}

		// find arr[high]%2==1
		//while(low<high && high>=0){
		// no need high>0, low acts as lower bound
		while(low<high && is_even(arr[high])){
			high--;
		}
		if(low < high){
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
}

/**
 output:
 11	9	7	1	3	3	5	2	4	2
 * */
