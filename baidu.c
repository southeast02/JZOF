#include <stdio.h>
#include <stdlib.h>

int partition(int nums[], int start, int end);
int find_single_times_element(int arr[], int s, int e);


int main(){
	int *arr;
	int n;
	int result;

	scanf("%d", &n);
	if((n & 1) == 0){
		printf("Total elements must be odd.\n");
	}
	arr = (int *)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}

	result = find_single_times_element(arr, 0, n-1);
	printf("Single element is %d\n", arr[result]);
	for(int i=0; i<n; i++){
		printf("%d", arr[i]);
		}
}


int find_single_times_element(int arr[], int s, int e){
	if(s == e){
		return s;
	}

	int pos = partition(arr, s, e);

	if((pos & 1) == 0){
		return find_single_times_element(arr, s, pos);
	} else {
		return find_single_times_element(arr, pos+1, e);
	}
}



int partition(int nums[], int start, int end){
	int elem;

	// 2 1 2 , after partition, the sequence is keep unchanged.
	if( (start != end) && (nums[start] == nums[end])){
		int temp = nums[start];
		nums[start] = nums[start+1];
		nums[start+1] = temp;
	}

	elem = nums[start];
	while(start < end){
		while(start < end && nums[end]>elem)
			end--;
		nums[start]=nums[end];
		while(start < end && nums[start] <= elem)
			start++;
		nums[end]=nums[start];
	}
	nums[start] = elem;
	return start;
}

/**
 * output
 5
1 2 2 1 3
Single element is 3
 * */
