
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_max_len(char* arr, int length);

int main(){
	char arr[51];
	scanf("%s", arr);
	printf("%d", get_max_len(arr, strlen(arr)));
    return 0;
}

int get_max_len(char* arr, int length){
	int max_len = 0;
	int temp_len = 0;

	for(int i=0; i<length; i++){
		temp_len = 0;
		for(int j=i; j<length; j++){
			if( arr[j] == 'A'||
				arr[j] == 'T'||
				arr[j] == 'C'||
				arr[j] == 'G'){
				temp_len++;
			}
			else{
				break;
			}
		}
		if(temp_len > max_len){
			max_len = temp_len;
		}
	}
	return max_len;
}

/**
 * input: ATCGABC
 * output: 5
 * */
