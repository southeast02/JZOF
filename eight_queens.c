#include <stdio.h>

void eight_queens(int arr[], int k);
void show_position(int arr[]);
int check_constraints(int arr[], int row, int col);

int count=0;

void main(){

	int arr[8];
	eight_queens(arr, 0);
	printf("finished! total solutions: %d\n", count);
}


void eight_queens(int arr[], int k){

	if(k == 8){
		show_position(arr);
		count++;
	}

	for(int i=0; i < 8; i++){
		if(check_constraints(arr, k, i)){//将第k行皇后放到第i列
			arr[k] = i;
			eight_queens(arr, k+1);
			//则撤销当前的这一步求解过程，回溯到上一步寻找其他求解路径。
			//为了能够撤销当前的求解过程，必须保存上一步以来的求解路径
			arr[k] = 0;
		}
	}
}

void show_position(int arr[]){

	for(int i=0; i<8; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int check_constraints(int arr[], int row, int col){

	for(int i=0; i<row; i++){
		if(arr[i] == col){
			return 0;
		}
	}

	for(int i=0; i<row; i++){
		if ( (col-arr[i] == row-i) ||
			 (col-arr[i] == i-row)){
			return 0;
		}
	}
	return 1;
}
/**
 * output:
 * 0 4 7 5 2 6 1 3 
0 5 7 2 6 3 1 4 
0 6 3 5 7 1 4 2 
0 6 4 7 1 3 5 2 
1 3 5 7 2 0 6 4 
1 4 6 0 2 7 5 3 
1 4 6 3 0 7 5 2 
1 5 0 6 3 7 2 4 
1 5 7 2 0 3 6 4 
1 6 2 5 7 4 0 3 
1 6 4 7 0 3 5 2 
1 7 5 0 2 4 6 3 
2 0 6 4 7 1 3 5 
2 4 1 7 0 6 3 5 
2 4 1 7 5 3 6 0 
2 4 6 0 3 1 7 5 
2 4 7 3 0 6 1 5 
2 5 1 4 7 0 6 3 
2 5 1 6 0 3 7 4 
2 5 1 6 4 0 7 3 
2 5 3 0 7 4 6 1 
2 5 3 1 7 4 6 0 
2 5 7 0 3 6 4 1 
2 5 7 0 4 6 1 3 
2 5 7 1 3 0 6 4 
2 6 1 7 4 0 3 5 
2 6 1 7 5 3 0 4 
2 7 3 6 0 5 1 4 
3 0 4 7 1 6 2 5 
3 0 4 7 5 2 6 1 
3 1 4 7 5 0 2 6 
3 1 6 2 5 7 0 4 
3 1 6 2 5 7 4 0 
3 1 6 4 0 7 5 2 
3 1 7 4 6 0 2 5 
3 1 7 5 0 2 4 6 
3 5 0 4 1 7 2 6 
3 5 7 1 6 0 2 4 
3 5 7 2 0 6 4 1 
3 6 0 7 4 1 5 2 
3 6 2 7 1 4 0 5 
3 6 4 1 5 0 2 7 
3 6 4 2 0 5 7 1 
3 7 0 2 5 1 6 4 
3 7 0 4 6 1 5 2 
3 7 4 2 0 6 1 5 
4 0 3 5 7 1 6 2 
4 0 7 3 1 6 2 5 
4 0 7 5 2 6 1 3 
4 1 3 5 7 2 0 6 
4 1 3 6 2 7 5 0 
4 1 5 0 6 3 7 2 
4 1 7 0 3 6 2 5 
4 2 0 5 7 1 3 6 
4 2 0 6 1 7 5 3 
4 2 7 3 6 0 5 1 
4 6 0 2 7 5 3 1 
4 6 0 3 1 7 5 2 
4 6 1 3 7 0 2 5 
4 6 1 5 2 0 3 7 
4 6 1 5 2 0 7 3 
4 6 3 0 2 7 5 1 
4 7 3 0 2 5 1 6 
4 7 3 0 6 1 5 2 
5 0 4 1 7 2 6 3 
5 1 6 0 2 4 7 3 
5 1 6 0 3 7 4 2 
5 2 0 6 4 7 1 3 
5 2 0 7 3 1 6 4 
5 2 0 7 4 1 3 6 
5 2 4 6 0 3 1 7 
5 2 4 7 0 3 1 6 
5 2 6 1 3 7 0 4 
5 2 6 1 7 4 0 3 
5 2 6 3 0 7 1 4 
5 3 0 4 7 1 6 2 
5 3 1 7 4 6 0 2 
5 3 6 0 2 4 1 7 
5 3 6 0 7 1 4 2 
5 7 1 3 0 6 4 2 
6 0 2 7 5 3 1 4 
6 1 3 0 7 4 2 5 
6 1 5 2 0 3 7 4 
6 2 0 5 7 4 1 3 
6 2 7 1 4 0 5 3 
6 3 1 4 7 0 2 5 
6 3 1 7 5 0 2 4 
6 4 2 0 5 7 1 3 
7 1 3 0 6 4 2 5 
7 1 4 2 0 6 3 5 
7 2 0 5 1 4 6 3 
7 3 0 2 5 1 6 4 
finished! total solutions: 92
 * */
