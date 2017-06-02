#include <stdio.h>

#define N 10

int duplicate(int data[], int length, int *duplication);

void main(){
	int data[N] = {1, 2, 3, 5, 4, 7, 8, 9, 6, 2};
	int number;
	int flag = duplicate(data, N, &number);

	if (flag){
		printf("duplication number: %d\n", number);
	} else{
		printf("no duplication numbers\n");
	}
}


int duplicate(int data[], int length, int *duplication){
	if(data == NULL || length <=0 ){
		return 0;
	}

	for(int i=0; i < length; i++){
		if(data[i] < 0 || data[i]>length-1){
			return 0;
		}
	}

	for(int i=0; i < length; i++){
		while(data[i] != i ){
			if(data[data[i]] == data[i]){
				*duplication = data[i];
				return 1;
			}
			int temp = data[i];
			data[i] = data[temp];
			data[temp] = temp;
			//int temp = data[i];
                        //data[i] = data[data[i]];
                        //data[data[i]] = temp; /* data[i] has been changed in last step*/
		}
	}
	return 0;
}
/**
 * output:
 * duplication number: 2
 * */
