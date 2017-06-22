#include <stdio.h>

extern void swap_with_zero(int* array, int len, int n);
void sort(int* array, int len);

int main(){

	int arr[] = {3, 8, 2, 4, 5, 0, 1, 7, 9, 6, 10};
	int len = 11;

	sort(arr, len);

	for(int i=0; i<len; i++){
		printf("%d\t", arr[i]);
	}

	return 0;
}

void sort(int* array, int len){
// there is a list with n numbers, but stored [0...n-1] with
// random order. you are only allowed to exchange position of
// a random number with 0, please implement the swap_with_zero
// and sort function. and use swap_with_zero in the sort to
// sort a list.
	int i, j;
	int pos_0;

	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			if(array[j] == 0){
				pos_0 = j;
				if(pos_0 == 0){
					int p=0;
					while(array[p] == p && p<len)
						p++;
					if(p==len) break;
					swap_with_zero(array, len, array[p]);
				}
			}
		}
		swap_with_zero(array, len, pos_0);
	}
}
void swap_with_zero(int* array, int len, int n){
	// array: a list with n numbers
	// len: list length
	// n: the number to be swapped with 0
	int pos_0, pos_n;
	int temp;
	for(int i=0; i<len; i++){
		if(array[i] == 0){
			pos_0 = i;
		}
		if(array[i] == n){
			pos_n = i;
		}
	}

	temp = array[pos_0];
	array[pos_0] = array[pos_n];
	array[pos_n] = temp;
}

/**
 * output:
 * 0	1	2	3	4	5	6	7	8	9	10
 * */
