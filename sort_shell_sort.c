#include <stdio.h>


int main(){
	int arr[] = {3, 5, 1, 23, 11, 2, 0, 5, 22};
	int len = 9;

	shell_sort(arr, len);

	for(int i=0; i<len; i++){
		printf("%d\t", arr[i]);
	}
}

void increment_sort(int arr[], int len, int incr){
	int i, j;
	int value;

	for(i=incr; i<len;i++){
		if(arr[i-incr] > arr[i]){
			value = arr[i];
			for(j=i-incr; j>=0 && arr[j]>value; j-=incr){
				arr[j+incr] = arr[j];
			}
			arr[j+incr] = value;
		}
	}
}

void shell_sort(int arr[], int len){
	int i;
	int incr[] = {9, 5, 3, 1};
	int nums = 4;

	for(i=0; i<nums; i++){
		increment_sort(arr, len, incr[i]);
	}
}

/**
 * output:
 * 0	1	2	3	5	5	11	22	23
 * */
