#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
	int x;
	int y;
}Point;


typedef struct{
	Point* routes;
	Point* routes_temp;
	int steps;
	int sum;
	int sum_temp;
}XNumber;

void move_forward(int arr[][4], int rows, int cols, int m, int n, XNumber* x);

int main()
{
	int arr[4][4] = {
			{1, 10, 3, 8},
			{12, 2, 9, 6},
			{5, 7, 4, 11},
			{3, 7, 16, 5},
	};
	int m=4;
	int n=4;
	XNumber x;
	x.routes = (Point *)malloc(sizeof(Point)*(m+n-1));
	x.routes_temp = (Point *)malloc(sizeof(Point)*(m+n-1));
	x.sum = INT_MIN;
	x.steps = 0;

	x.sum_temp=arr[0][0];
	move_forward(arr, m, n, 0, 0, &x);
	printf("\nThe max gift value is :%d\n", x.sum);
	printf("The gifts are: ");
	for(int i=0; i<= m+n-2; i++){
		printf("%d ", arr[x.routes[i].x][x.routes[i].y]);
	}
	return 0;
}

void move_forward(int arr[][4], int rows, int cols, int m, int n, XNumber* x){
	if(x->steps==rows+cols-2){ //m==rows-1 && n==cols-1
		if(x->sum_temp > x->sum){
			for(int i=0; i<=x->steps; i++){
				x->routes[i].x = x->routes_temp[i].x;
				x->routes[i].y = x->routes_temp[i].y;
			}
			x->sum = x->sum_temp;
		}
		x->steps = 0;
		x->sum_temp = arr[0][0];
	}
	for(int k=0; k<2; k++){
		int step_temp;
		int sum_temp;

		if(k==0){
			if(m+1 < rows){
				step_temp = x->steps;
				sum_temp = x->sum_temp;
				x->steps++;
				x->sum_temp += arr[m+1][n];
				x->routes_temp[x->steps].x = m+1;
				x->routes_temp[x->steps].y = n;
				move_forward(arr, rows, cols, m+1, n, x);
				x->steps = step_temp;
				x->sum_temp = sum_temp;
			}
		} else {
			if(n+1 < cols){
				x->steps++;
				x->sum_temp += arr[m][n+1];
				x->routes_temp[x->steps].x = m;
				x->routes_temp[x->steps].y = n+1;
				move_forward(arr, rows, cols, m, n+1, x);
			}
		}
	}
}


/**
 * output:
The max gift value is :53
The gifts are: 1 12 5 7 7 16 5 
 * */
