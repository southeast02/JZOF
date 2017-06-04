#include <stdio.h>

int FindNumber(int arr[][4], int row, int col, int number);
int FindNumberFromUpRight(int arr[][4], int row, int col, int number);

void main(){
	int arr[4][4] = {
			{1, 2, 7, 9},
			{2, 4, 9, 12},
			{4, 7, 10, 13},
			{6, 8, 11, 15}
	};
	int number = 7;
    //int flag = FindNumber(arr, 4, 4, number);
	int flag = FindNumberFromUpRight(arr, 4, 4, number);

	if(flag){
		printf("Found number %d\n", number);
	} else {
		printf("Not found number %d\n", number);
	}
}

int FindNumber(int arr[][4], int row, int col, int number){
	int start = 0;
	int end = col-1;
	int middle;

	for(int i=0; i < row; i++){
		start = 0;
		end = col -1;
		while(start <= end){
			middle = (start + end)/2;
			if (arr[i][middle] == number){
				return 1;
			}
			else if(arr[i][middle] < number){
				start = middle + 1;
			} else{
				end = middle - 1;
			}
		}
	}
	return 0;
}

int FindNumberFromUpRight(int arr[][4], int row, int col, int number){

	int j = col -1;
	int i = 0;

	while(j >= 0 && i < row){
		if(arr[i][j] == number){
			return 1;
		} else if (arr[i][j] > number){
			j--; // no need to judge what if j-- has overflowed
		} else {
			i++; // no need to judge what if i++ has overflowed
		}
	}
	return 0;
}

/**
 * output:
 * Found number 7
 * */
