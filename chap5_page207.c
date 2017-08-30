#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number;
	int is_valid;
}XNumber;

XNumber get_x_length_number(int nums[], int N);
int check_is_valid_x_length(int nums[], int N, int x);
int partition(int nums[], int start, int end);

int main()
{
	int arr[] = {4, 3};
	int N = 2;
	XNumber x;

	x = get_x_length_number(arr, N);
	puts("elements in array:");
	for(int i=0; i<N; i++)
		printf("%d ", arr[i]);
	puts("");

	if(x.is_valid){
		printf("%d turns up more than %d times\n", x.number, N>>1);
	}else{
		printf("No element turns up  more than %d times", N>>1);
	}
}


XNumber get_x_length_number(int nums[], int N){
	int start;
	int end;
	int middle_place;
	int pivot;
	int result;
	XNumber res;

	start = 0;
	end = N-1;
	if((N & 0x1)==0) middle_place = N/2-1;
	else middle_place = (N-1)/2;

	pivot = partition(nums, start, end);
	while(pivot != middle_place){
		if(pivot < middle_place){
			start = pivot+1;
			pivot = partition(nums, start, end);
		}
		else{
			end = pivot-1;
			pivot = partition(nums, start, end);
		}
	}

	result = check_is_valid_x_length(nums, N, nums[middle_place]);
	res.number = nums[middle_place];
	res.is_valid = result;

	return res;
}


int check_is_valid_x_length(int nums[], int N, int x){
	int times = 0;
	int i;
	int result;

	for(i=0; i<N; i++){
		if(nums[i] == x){
			times++;
		}
	}

	result = 0;
	if(2*times > N){
		result = 1;
	}

	return result;
}

int partition(int nums[], int start, int end){
	int elem;

	elem = nums[start];
	while(start < end){
		while(start < end && nums[end]>elem)
			end--;
		nums[start]=nums[end];
		start++;
		while(start < end && nums[start]<elem)
			start++;
		nums[end]=nums[start];
		end--;
	}
	nums[start] = elem;
	return start;
}

/*
 * output:
elements in array:
4 3 4 5 4
4 turns up more than 2 times


elements in array:
3 4
No element turns up  more than 1 times

 * */
