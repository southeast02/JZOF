#include <stdio.h>

void main(){

	int array[] = {3, 5, 24, 2, 1, 0};
	int number = 6;

	heap_sort(array, number);

	for(int i=0; i<number; i++){
		printf("%d\t", array[i]);
	}
}

void heap_adjust(int arr[], int s, int m){

	int i;
	int value;

	value = arr[s];
	for(i=2*s+1; i<=m; i=i*2+1){
		if(i<m){
			if(arr[i] < arr[i+1]){
				i++;
			}
		}
		if(value >= arr[i]){
			break;
		}
		arr[s] = arr[i];
		s = i;
	}
	arr[s] = value;
}

void heap_sort(int arr[], int length){

	int i,  j;
	int index;
	int temp;

	for(i=length/2-1; i>=0; i--){
		heap_adjust(arr, i, length-1);
	}

	for(i=length-1; i>0; i--){
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heap_adjust(arr, 0, i-1);
	}
}


/**
 * output:
 * 0	1	2	3	5	24
 * */
