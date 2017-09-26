
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int value;
	int nums;
}COIN;

int main() {
	COIN c[6];
	int price;
	int n = 6;
	int sum;
	int count;
	int j;

	c[0].value = 1;
	c[1].value = 5;
	c[2].value = 10;
	c[3].value = 50;
	c[4].value = 100;
	c[5].value = 500;

	for(int i=0; i<n; i++){
		scanf("%d", &(c[i].nums));
	}
	scanf("%d", &price);

	sum = price;
	count = 0;
	for(int i=n-1; i>=0; i--){
		j = 0;
		while(sum >= c[i].value && j < c[i].nums){
			sum -= c[i].value;
			count++;
			j++;
		}
		if(sum == 0){
			break;
		}
	}
	if(sum == 0){
		printf("%d", count);
	}else {
		printf("NOWAY");
	}

	return 0;
}



//3 2 1 3 0 2 620
//4
