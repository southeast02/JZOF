#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *nums;
	int length;
}XNumber;


int get_max(int arr[]); // when remove the max element in heap, arr[1...length] is still heap-like
void heap_adjust(int arr[], int s, int length);// arr[s+1...length] has been heap-like
void heap_sort(int arr[], int length);
XNumber get_k_min_elements(int arr[], int N, int k);


int main()
{
	int arr[] = {4, 3, 2, 1, 8};
	int N = 5;
	int k=4;
	XNumber x;

	x = get_k_min_elements(arr, N, k);

	for(int i=0; i<k; i++){
		printf("%d ", x.nums[i]);
	}
	return 0;
}

XNumber get_k_min_elements(int arr[], int N, int k){
	XNumber x;
	int temp;

	x.length = 0;
	if(k<1 || k>N){
		return x;
	}

	x.nums = (int *)malloc(sizeof(int)*k);

	for(int i=0; i<N; i++){
		if(x.length < k){
			x.nums[x.length++]=arr[i];
			if(x.length > 1){
				temp = x.nums[0];
				x.nums[0]= x.nums[x.length-1];
				x.nums[x.length-1] = temp;
				heap_adjust(x.nums, 0, x.length-1);
			}
		}
		else if(x.length == k){
			if(x.nums[0] <= arr[i]){
				continue;
			} else{
				x.nums[0] = arr[i];
				heap_adjust(x.nums, 0, x.length);
			}
		}
	}
	return x;

}


int get_max(int arr[]){
	return arr[0];
}

void heap_adjust(int arr[], int s, int length){
	int elem = arr[s];
	for(int j=s*2+1; j<length; j = j*2+1){
		if(j+1 < length){
			if(arr[j] < arr[j+1])
				j++;
		}
		if(arr[j] <= elem){
			break;
		}
		arr[s] = arr[j];
		s = j;
	}
	arr[s] = elem;
}


void heap_sort(int arr[], int length){
	int temp;

	for(int i=length/2-1; i>=0; i--){
		heap_adjust(arr, i, length);
	}

	for(int i=length-1; i>=0; i--){
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heap_adjust(arr, 0, i);
	}
}


/*
 * output:
3 2 1 4 
 * */
