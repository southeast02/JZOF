#include <stdio.h>
#include <stdlib.h>

void main(){
	int value;
	int n;

	n = 12;
	value = fibonacci(n);
	printf("fibonacci(%d) = %d\n", n, value);
}

int fibonacci(int n){
	int arr[2];
	int return_value;

	//arr = (int*)malloc(sizeof(int) * n);

	for(int i=0; i<n; i++){
		if(i==0 || i==1){
			arr[i] = 1;
			return_value = arr[i];
		} else{
			//arr[i] = arr[i-1] + arr[i-2]; //arr[0...n-2] isn't needed
			return_value = arr[0] + arr[1];
			arr[0] = arr[1];
			arr[1] = return_value;
		}
	}
	return return_value;
}

/**
 * output:
 * fibonacci(12) = 144
 * */
