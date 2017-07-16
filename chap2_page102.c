#include <stdio.h>

#define N 256

int numberOf1(int n);
int numberOf1_1(int n);

int main(){
	int value = 11;

	printf("number of 1 is: %d\n", numberOf1(value));
	printf("number of 1 is: %d\n", numberOf1_1(value));
	return 0;
}

int numberOf1(int n){
	int count=0;
	unsigned int flag = 1;

	while(flag){
		if(n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int numberOf1_1(int n){
	int count=0;

	while(n){
		count++;
		n = (n-1)&n;
	}
	return count;
}


/**
 * output:
 * number of 1 is: 3
 * */
