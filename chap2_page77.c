#include <stdio.h>
#include <stdlib.h>

int count=0;

void get_totals(int n);
int get_totals_2(int n);

void main(){
	int value;
	int n;

	n = 11;
	get_totals(n);
	printf("get_totals(%d) = %d\n", n, count);

	value = get_totals_2(n);
	printf("get_totals_2(%d) = %d\n", n, count);
}

void get_totals(int n){ // 回溯法
	// initial condition: n>0
	if(n == 0){
		count ++;
		return;
	} else if(n < 0){
		return;
	} else {
		get_totals(n-1);
		get_totals(n-2);
	}
}

int get_totals_2(int n){ //动态规划
	if(n==1 || n==2){
		return 1;
	}

	return get_totals_2(n-1) + get_totals_2(n-2);
}

/**
output:
get_totals(11) = 144
get_totals_2(11) = 144
 * 
 * */
