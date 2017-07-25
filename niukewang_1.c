#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int odd_alpha_sum(int freq[]);
void compute_alpha_frequency(char *arr, int freq[], int length);

int main(){
	char arr[1001];
	int freq[26] = {0};
	scanf("%s", arr);
	compute_alpha_frequency(arr, freq, strlen(arr));
	printf("%d", odd_alpha_sum(freq));
    return 0;
}

void compute_alpha_frequency(char *arr, int freq[], int length){
	for(int i=0; i<length; i++){
		freq[arr[i]-'a']++;
	}
}

int odd_alpha_sum(int freq[]){
	int sum=0;

	for(int i=0; i<27; i++){
		if(freq[i] % 2 == 1){
			sum++;
		}
	}
	return sum;
}

/**
 * input: abc
 * output: 3
 * */
