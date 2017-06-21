#include <stdio.h>

void main(){

	int array[] = {3, 5, 24, 2, 1, 0};
	int number = 6;

	selection_sort(array, number);

	for(int i=0; i<number; i++){
		printf("%d\t", array[i]);
	}
}

void selection_sort(int array[], int length){

	int i,  j;
	int index;
	int temp;

	for(i = 0; i< length-1; i++){
		index = i;

		for(j=i+1; j<length; j++){
			if(array[index] > array[j]){
				index = j;
			}
		}
		if(i != index){
			temp = array[index];
			array[index] = array[i];
			array[i] = temp;
		}
	}
}


/**
 * output:
 * 0	1	2	3	5	24
 * */
