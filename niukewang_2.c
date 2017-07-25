#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_len(char *arr, int len);
int is_ouchuan(char *arr, int len);

int main(){
	char arr[201];
//	if(is_ouchuan(arr, strlen(arr))){
//		puts("yes");
//	}
	scanf("%s", arr);

	printf("%d", max_len(arr, strlen(arr)-1));
    return 0;
}

int max_len(char *arr, int len){
	int temp_len=len;
	while(!is_ouchuan(arr, temp_len)){
		temp_len--;
	}
	return temp_len;
}

int is_ouchuan(char *arr, int len){
	int low = 0;
	int middle=len/2;
	int high = middle;

	if(len % 2 == 1){
		return 0;
	}

	while(low < middle && arr[low]==arr[high]){
		low++;
		high++;
	}
	if(low == middle){
		return 1;
	}
	return 0;
}

/**
 * input: abcabcabc
 * output: 6
 * */
