#include <stdio.h>

void main(){

	int array[] = {3, 5, 24, 2, 1, 0};
	int number = 6;

	quick_sort(array, number);

	for(int i=0; i<number; i++){
		printf("%d\t", array[i]);
	}
}

int partition(int array[], int low, int high){

	int pivotkey = array[low];

	while(low < high){
		while(low < high && array[high] >= pivotkey)
			high--;
		array[low] = array[high];
		while(low < high && array[low] <= pivotkey)
			low++;
		array[high] = array[low];
	}
	array[low] = pivotkey;
	return low;
}

void q_sort(int array[], int low, int high){

	if(low < high){
		int pivotindex = partition(array, low, high);
		q_sort(array, low, pivotindex-1);
		q_sort(array, pivotindex+1, high);
	}
}

void quick_sort(int array[], int length){

	q_sort(array, 0, length-1);
}

/**
 * output:
 * 0	1	2	3	5	24
 * */
