#include <stdio.h>
#include <string.h>

void fun(int arr[], int n);


void main(){
	int arr[] = {1, 2, 3};
	fun(arr, 3);
	for(int i=0; i<3; i++)
		printf("%d\n", arr[i]);
}

void fun(int arr[], int n){
	for(int i=0; i<n; i++ ){
		arr[i] +=1;
	}
}

/**
 * output:
 * 2
   3
   4
 * */
