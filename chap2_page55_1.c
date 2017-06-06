#include <stdio.h>

void ChainSortedArray(int A1[], int A2[], int len1, int len2);

#define N 20

int main(){
	int A1[N]=  {4, 5, 7}; // assume that A1 has enough space, so we should assign more space than needed
	int A2[] = {6, 8, 14};

	ChainSortedArray(A1, A2, 3, 3);

	for(int i=0; i<6; i++){
		printf("%d\t", A1[i]);
	}

	return 0;
}


void ChainSortedArray(int A1[], int A2[], int len1, int len2){
	int i = len1-1;
	int j = len2-1;
	int k = len1 + len2 -1; // put each element to targeted position

	while(i>=0 && j>=0){
		if(A1[i] >= A2[j]){
			A1[k--] = A1[i--];
		} else {
			A1[k--] = A2[j--];
		}
	}

	while(j>=0){ // if A1 has left elements, it needs no changes.
		A1[k--] = A2[j--];
	}
}

/**
 * output:
 * 4	5	6	7	8	14
 * */
