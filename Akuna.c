#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int count_sequence(long int num);


int main() {
	int num =15;
	int count;

	count = count_sequence(num);
	printf("%d kinds of consective sum.\n", count);
	return 0;
}


int count_sequence(long int N){
	int count = 0;
	int x, k, m; // k denotes length of sequence

	k=2;
	while(1){
		x = (N - k*(k-1)/2) / k;//start valud of sequence
		m = (N - k*(k-1)/2) % k; //whether we have continous sequence
		if(x <= 0) break; // x<=0 then quit while loop
		if(!m){ // we find continous sequence
			count++;
		}
		k++;
	}
	return count;
}

/**
 * output
 *
 * 3 kinds of consective sum.
 *
 * */
