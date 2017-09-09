
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int rearrange_array(int arr[], int n);

 int main()
{
	int *arr;
	int *outcome;
	int n;
	int times;
	int ret;

	scanf("%d", &times);
	outcome = (int *)malloc(sizeof(int) * times);

	for(int i=0; i< times; i++){
		scanf("%d", &n);

		arr = (int *)malloc(sizeof(int) * n);

		for(int i=0; i<n; i++){
			scanf("%d", arr+i);
		}

		// start computing
		ret = rearrange_array(arr, n);
		outcome[i] = ret;
	}

	for(int i=0; i<times; i++){
		if(outcome[i]){
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}


 int rearrange_array(int arr[], int n){
	 int m1=0;// arr[i] % 4 == 0
	 int m2=0; // arr[i] % 2 ==0 and arr[i]%4!=0
	 int sum = n/2;

	 // get m1 and m2
	 for(int i=0; i< n; i++){
		 if(arr[i] % 4 == 0){
			 m1++;
		 } else if( arr[i] % 2 == 0){
				 m2++;
		 }
	 }

	 if(m1 + m2/2 >= sum){
		 return 1;
	 }
	 return 0;

 }

/**
 * output:
2 4
1 2 3 5
3
5 2 3
No
No
 * */
