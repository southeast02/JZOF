#include <stdio.h>

#define N 10


int main(){
	int data[N] = {1, 3, 3, 5, 2, 3, 5, 6, 0, 6};
	int data_freq[N] = {0};

	for(int i=0; i < N; i++){
		data_freq[data[i]] += 1;
	}

	for(int i=0; i < N; i++){
		if(data_freq[i] > 1){
			printf("number = %d\t frequency = %d\n", i, data_freq[i]);
		}
	}

}

/**
 * output:
 * number = 3	 frequency = 3
   number = 5	 frequency = 2
   number = 6	 frequency = 2
 *
 * */
