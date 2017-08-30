#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* number;
	int len;
}XNumber;

XNumber get_k_min_numbers(int nums[], int N, int k);
int partition(int nums[], int start, int end);

int main()
{
	int arr[] = {4, 3, 2, 1, 8};
	int N = 5;
	XNumber x;
	int k = 2;

	x = get_k_min_numbers(arr, N, k);

	for(int i=0; i<k; i++){
		printf("%d ", x.number[i]);
	}

	return 0;
}


XNumber get_k_min_numbers(int nums[], int N, int k){
	int start;
	int end;
	int pivot;
	XNumber res;

	res.len = k;
	res.number = (int *)malloc(sizeof(int) * res.len);
	start = 0;
	end = N-1;

	pivot = partition(nums, start, end);
	while(pivot != k-1){
		if(pivot < k-1){
			start = pivot+1;
			pivot = partition(nums, start, end);
		}
		else{
			end = pivot-1;
			pivot = partition(nums, start, end);
		}
	}
	for(int i=0; i<k; i++){
		res.number[i] = nums[i];
	}

	return res;
}


int partition(int nums[], int start, int end){
	int elem;
	elem = nums[start];
	while(start < end){
		while(start < end && nums[end]>=elem)
			end--;
		nums[start]=nums[end];
//		start++; // because after while loop there is a num[]=num[] anyway
		// if s == e, then s++ is not necessary.
		while(start < end && nums[start]<=elem)
			start++;
		nums[end]=nums[start];
//		end--;
	}
	nums[start] = elem;

	return start;
}

/*
 * output:
1 2 3


1 2 
 * */
