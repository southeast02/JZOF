#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int translate_integers(int num);

int main()
{
	int num = 28;
	int ret;

	if(num<=0){
		printf("%d is invalid\n", num);
	}
	ret = translate_integers(num);
	printf("Total translation ways: %d\n", ret);

	return 0;
}


int translate_integers(int num){
	int count;
	int length;
	char nums[11];
	int *counts;
	int digit[2];
	int number;

	length = sprintf(nums, "%d", num);
	counts = (int *)malloc(sizeof(int)*length);
	for(int i=length-1; i>=0; i--){
		count = 0;

		if(i < length-1){
			count += counts[i+1];
		}else{
			count = 1;
		}

		if(i < length-1){
			digit[0] = nums[i+1]-'0';
			digit[1] = nums[i]-'0';
			number = digit[1]*10+digit[0];
			if(number >= 10 && number<=25){
				if(i+2 < length){
					count += counts[i+2];
				}else{
					count += 1;
				}
			}
		}
		counts[i] = count;
	}
	count = counts[0];
	free(counts);

	return count;
}

/**
 * output:

Total translation ways: 5

Total translation ways: 2
 * */
