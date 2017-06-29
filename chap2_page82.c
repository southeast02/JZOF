#include <stdio.h>

int minor_number_in_list(int arr[], int len);
int find_min_number(int arr[], int s, int m);

void main(){

	int arr[] = {1};
	int len = 1;


	int ret;
	ret = minor_number_in_list(arr, len);
	printf("minimum value in list is %d\n", ret);
}

int minor_number_in_list(int arr[], int len){
	// list is rotated list, get the minimum item in list
	int low = 0;
	int high = len-1;
	int mid;

	while(arr[low] >= arr[high]){
		if(high-low == 1){
			break;
		}

		mid = (low+high)/2;
		if(arr[low] == arr[high] && arr[mid] == arr[low]){
			return find_min_number(arr, low, high);
		}

		if(arr[mid] >= arr[low]){
			low = mid;
		} else if(arr[mid] <= arr[high]){
			high = mid;
		}
	}

	// two exits cases.
	if(arr[low] <= arr[high]){
		return arr[0];
	}

	return arr[high];
}

int find_min_number(int arr[], int s, int m){
	// find minimum item in arr[s...m]
	int value = arr[s];

	for(int i=s+1; i<=m; i++){
		if(arr[i] < value){
			value = arr[i];
		}
	}
	return value;
}

/**
 * output:
 * minimum value in list is 1
 * */
