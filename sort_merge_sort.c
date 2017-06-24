#include <stdio.h>
#include <stdlib.h>

//void merge_sort(int arr[], int tr[], int len);
//void merge(int arr[], int tr[], int s, int m, int n);

void main(){
	int arr[] = {3, 5, 1, 4, 9, 2, 3, 6};
	int len = 8;

	merge_sort(arr, arr, len);
	for(int i=0; i<len; i++){
		printf("%d\t", arr[i]);
	}
}

void merge(int arr[], int tr[], int n){
	// arr: source list of numbers
	// tr: target list of merged numbers
	// s: start index of group 1
	// m: end index of group 1
	// n: end index of group 2
	int i, j, p;
	int m;

	i = 0;
	m = j = (n+1)/2;
	p = 0;
	while(i<m && j<n){
		if(arr[i] <= arr[j]){
			tr[p++] = arr[i++];
		} else {
			tr[p++] = arr[j++];
		}
	}
	while(i<m){
		tr[p++] = arr[i++];
	}
	while(j<n){
		tr[p++] = arr[j++];
	}
}

//void merge_sort(int arr[], int tr[], int s, int t){
//	if(s == t){
//		tr[s] = arr[s];
//		return;
//	} else {
//		int m = (s+t)/2;
//		int temp[9];
//
//		merge_sort(arr, temp, s, m);
//		merge_sort(arr, temp, m+1, t);
//		merge(temp, tr, s, m+1, t+1);
//	}
//}

void merge_sort(int arr[], int tr[], int len){
	if(len == 1){ // tr and arr will overlay, so temporary space should be used.
		tr[0] = arr[0];
	} else {
		int m = (len+1)/2;
		int temp[9];

		merge_sort(arr, temp, m);
		merge_sort(arr+m, temp+m, len-m);
		merge(temp, tr, len);
	}
}

/**
 * output:
 * 1	2	3	3	4	5	6	9
 * */
