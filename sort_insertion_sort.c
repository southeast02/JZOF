#include <stdio.h>

void main(){

	int array[] = {3, 5, 24, 2, 1, 0};
	int number = 6;

	insertion_sort(array, number);

	for(int i=0; i<number; i++){
		printf("%d\t", array[i]);
	}
}

void insertion_sort(int arr[], int length){

	int i, j;
	int value;
	
	for(i=1; i<length; i++){
		if( arr[i] < arr[i-1]){
			value = arr[i];
			for(j=i-1; j>=0 && arr[j]>value; j--){
				arr[j+1] = arr[j];
			}
			arr[j+1] = value;
		}
	}
}


/**
 * output:
 * 0	1	2	3	5	24
 * */
