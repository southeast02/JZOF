#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get(int len, char **arr);
int get_core(int len, char **arr, char tail, int *used, int count);

int main(){
	char* arr[] = {
			"am",
			"mp",
			"pz",
			"zm",
			"ma"};


	int result = get(5, arr);
	if(result==1){
		puts("1");
	} else {
		puts("-1");
	}

	return 0;
}



int get(int len, char **arr){
	int *used;
	int result;

	used = (int *)malloc(sizeof(int)*len);

	for(int i=0; i<len; i++){
		used[i]=0;
	}

	for(int i=0; i<len; i++){
		used[i]=1;
		result=get_core(len, arr, arr[i][strlen(arr[i])-1], used, 1);
		if(result == 1){
			return 1;
		} else {
			used[i] = 0;
		}
	}
	return result;
}

int get_core(int len, char **arr, char tail, int *used, int count){
	if(count == len){
		return 1;
	}

	for(int i=0; i<len; i++){
		if(!used[i] && (arr[i][0]==tail)){
			used[i] = 1;
			if(!get_core(len, arr, arr[i][strlen(arr[i])-1], used, count+1)){
				used[i]=0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}
