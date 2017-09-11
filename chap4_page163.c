#include <stdio.h>
#include <stdlib.h>

void print_metrix(int** arr, int m, int n);



int main(){
	int m;
	int n;
	int **arr;

	scanf("%d", &m);
	scanf("%d", &n);

//	int arr[m][n];

	arr = (int **)malloc(sizeof(int*)*m);
	for(int i=0; i<m; i++){
		arr[i] = (int *)malloc(sizeof(int)*n);
	}

	for(int i=0; i<m; i++){
		for(int j = 0; j<n; j++)
			scanf("%d", &arr[i][j]);
	}


	print_metrix(arr, m, n);
}


void print_metrix(int** arr, int m, int n){
	int round = 0;
	int i= 0;
	int j = 0;

	while(i < m && j < n){
		while(j < n){
			printf("%d, ", arr[i][j]);
			j++;
		}


		if (j == n)
			j--;
		while(i < m-1){
			i++;
			printf("%d, ", arr[i][j]);
		}

		while(j > round && i > round){// i > round, because first line has been printed.
			j--;
			printf("%d, ", arr[i][j]);
		}


		while(i > round+1 && j < n-1){//j < n-1, because last column has been printed.
			i--;
			printf("%d, ", arr[i][j]);
		}

		j++;
		round++;
		m--;
		n--;
	}
}


/**
 *output
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10,


2 3
1 2 3
4 5 6
1, 2, 3, 6, 5, 4,

 1 4
1 2 3 4
1, 2, 3, 4,

4 1
1 2 3 4
1, 2, 3, 4,

 1 1
1
1,
 * */
