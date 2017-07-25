//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int odd_alpha_sum(int freq[]);
//void compute_alpha_frequency(char *arr, int freq[], int length);
//
//int main(){
//	char arr[1001];
//	int freq[26] = {0};
//	scanf("%s", arr);
//	compute_alpha_frequency(arr, freq, strlen(arr));
//	printf("%d", odd_alpha_sum(freq));
//    return 0;
//}
//
//void compute_alpha_frequency(char *arr, int freq[], int length){
//	for(int i=0; i<length; i++){
//		freq[arr[i]-'a']++;
//	}
//}
//
//int odd_alpha_sum(int freq[]){
//	int sum=0;
//
//	for(int i=0; i<27; i++){
//		if(freq[i] % 2 == 1){
//			sum++;
//		}
//	}
//	return sum;
//}
//
///**
// * input: abc
// * output: 3
// * */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int max_len(char *arr, int len);
//int is_ouchuan(char *arr, int len);
//
//int main(){
//	char arr[201];
////	if(is_ouchuan(arr, strlen(arr))){
////		puts("yes");
////	}
//	scanf("%s", arr);
//
//	printf("%d", max_len(arr, strlen(arr)-1));
//    return 0;
//}
//
//int max_len(char *arr, int len){
//	int temp_len=len;
//	while(!is_ouchuan(arr, temp_len)){
//		temp_len--;
//	}
//	return temp_len;
//}
//
//int is_ouchuan(char *arr, int len){
//	int low = 0;
//	int middle=len/2;
//	int high = middle;
//
//	if(len % 2 == 1){
//		return 0;
//	}
//
//	while(low < middle && arr[low]==arr[high]){
//		low++;
//		high++;
//	}
//	if(low == middle){
//		return 1;
//	}
//	return 0;
//}
///**
// * input: abcabcabc
// * output: 6
// * */

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
