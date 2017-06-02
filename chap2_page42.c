
#include <stdio.h>

#define N 10

int countRange(int start, int end, int data[], int length);
int BinaryFindDuplicate(int start, int end, int data[], int length, int *duplication);
int duplicate(int data[], int length, int *duplication);


void main(){
	int data[N] = {1, 2, 3, 5, 4, 7, 8, 9, 6, 3};
	int number;
    //int flag = BinaryFindDuplicate(1, N-1, data, N, &number);
	int flag = duplicate(data, N, &number);

	if(flag){
		printf("duplication number: %d\n", number);
	} else {
		printf("no duplication numbers\n");
	}

}


int countRange(int start, int end, int data[], int length){
	int count = 0;

	if(data == NULL){
		return 0;
	}

	for(int i=0; i < length; i++){
		if(data[i] >= start && data[i] <= end){
			count ++;
		}
	}
	return count;
}

int BinaryFindDuplicate(int start, int end, int data[], int length, int *duplication){
	if(start > end) return 0;
	if(start == end){
		if(countRange(start, end, data, length) > 1){
			*duplication = start;
			return 1;
		}
		return 0;
	}
	if(countRange(start, (start+end)/2, data, length) > (end-start)/2 + 1){
		return BinaryFindDuplicate(start, (start+end)/2, data, length, duplication);
	} else{
		return BinaryFindDuplicate((start+end)/2+1, end, data, length, duplication);
	}
}

int duplicate(int data[], int length, int *duplication){
	int start = 1;
	int end = length -1;

	if(data == NULL || length <= 0){
		return 0;
	}

	while(start <= end){
		if(start == end){
			if(countRange(start, end, data, length) > 1){
				*duplication = start;
				return 1;
			}
			return 0;
		}
		if(countRange(start, (start+end)/2, data, length) > (end-start)/2+1){
			end = (start + end)/2;
		} else {
			start = (start + end)/2 + 1;
		}
	}
	return 0;
}

/**
 * output:
 * duplication number: 3
 * */
