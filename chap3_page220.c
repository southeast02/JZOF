#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int start;
	int end;
	int sum;
}XNumber;

XNumber get_continous_max_sum(int nums[], int length);

int main()
{
	int arr[] = {-1, -2, 3, 10, -4, 7, 2, -5};
	int N = 8;
	XNumber x;
	x = get_continous_max_sum(arr, N);

	printf("continous sub-array: ");
	for(int i=x.start; i<=x.end; i++){
		printf("%d ", arr[i]);
	}
	printf("\nmax sum = %d\n", x.sum);
	return 0;
}


XNumber get_continous_max_sum(int nums[], int length){
	XNumber x;
	int sum_temp;

	x.start = 0;
	x.end = 0;
	x.sum = INT_MIN;
	sum_temp = x.sum;

	for(int i=0; i<length; i++){
		if( sum_temp  <= 0){ // discard old sub-array and restart
            sum_temp = nums[i];
		}  else{ // extend temp sub-array
			sum_temp+=nums[i];
		}

		if(sum_temp > x.sum){
			if(sum_temp == nums[i]){ // restart
				x.start = i;
				x.end = i;
				x.sum = sum_temp;
			} else{ // extend
				x.end = i;
				x.sum = sum_temp;
			}
		}
	}
	return x;
}

/*
 * output:
continous sub-array: -1
max sum = -1

continous sub-array: 3 10
max sum = 13

continous sub-array: 3 10 -4 7
max sum = 16

continous sub-array: 3 10 -4 7 2 
max sum = 18
 * */
