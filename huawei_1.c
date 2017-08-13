#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rearrange_list(char* array, int length, int* len1, int* len2);
void bubble_sort(char* array, int length);

int main(){

//	char arr[] = {'a', 'A', '6', '3', '4', 'p', 'H', 'i'};
	int len;
	int len1, len2;
	char arr[256];

	scanf("%s", arr);

	len = strlen(arr);

	rearrange_list(arr, len, &len1, &len2);
	// sort 'a'-'z'
	bubble_sort(arr, len1);
	// sort 'A'-'Z'
	bubble_sort(arr+len1, len2);
	// sort '0'-'9'
	bubble_sort(arr+len1+len2, len-len1-len2);

	puts(arr);
	return 0;
}


void bubble_sort(char* array, int length){

	int i, j;
	int CHANGED = 1;
	char temp;

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

void rearrange_list(char* array, int length, int* len1, int* len2){
	char *arr = (char *)malloc(sizeof(char) * length);
	int i, j;


	//find 'a'-'z'
	j=0;
	for(i=0; i<length; i++){
		if(array[i]>='a' && array[i]<='z'){
			arr[j++] = array[i];
		}
	}
	*len1 = j;

	// find 'A'-'Z'
	for(i=0; i<length; i++){
		if(array[i]>='A' && array[i]<='Z'){
			arr[j++] = array[i];
		}
	}
	*len2 = j-*len1;
	// find '0'-'9'
	for(i=0; i<length; i++){
		if(array[i]>='0' && array[i]<='9'){
			arr[j++] = array[i];
		}
	}

	for(i=0; i<length; i++){
		array[i] = arr[i];
	}
}


/**
 * input:
 * af83AG
 * output:
 * afAG38
 * */
