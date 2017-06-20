#include <stdio.h>

void main(){

	int array[] = {3, 5, 24, 2, 1, 0};
	int number = 6;

	bubble_sort(array, number);

	for(int i=0; i<number; i++){
		printf("%d\t", array[i]);
	}

}

void bubble_sort(int array[], int length){

	int i, j;
	int CHANGED = 1;
	int temp;

	for(i=1; i < length && CHANGED; i++){
		CHANGED = 0;
		for(j=0; j<length-i; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				CHANGED = 1;
			}
		}
	}
}

/**
 * output:
 * 0	1	2	3	5	24	
 * */
