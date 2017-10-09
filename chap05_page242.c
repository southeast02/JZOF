#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int get_ugly_number(int index);
int min(int number1, int number2, int number3);


int main() {
	int index = 1500;
	int ugly_number = get_ugly_number(index);

	printf("Ugly number at %d is %d\n", index, ugly_number);

	return 0;
}


int get_ugly_number(int index){
	if(index <= 0){
		return 0;
	}

	int *ugly_numbers;
	ugly_numbers = (int *)malloc(sizeof(int)*index);
	ugly_numbers[0] = 1;
	int next_ugly_index = 1;

	int *ugly_multiply2 = ugly_numbers;
	int *ugly_multiply3 = ugly_numbers;
	int *ugly_multiply5 = ugly_numbers;

	while(next_ugly_index < index){
		int min_number = min(*ugly_multiply2 * 2,
				*ugly_multiply3 * 3, *ugly_multiply5 * 5);
		ugly_numbers[next_ugly_index] = min_number;

		while(*ugly_multiply2 * 2 <= ugly_numbers[next_ugly_index])
			ugly_multiply2++;
		while(*ugly_multiply3 * 3 <= ugly_numbers[next_ugly_index])
					ugly_multiply3++;
		while(*ugly_multiply5 * 5 <= ugly_numbers[next_ugly_index])
					ugly_multiply5++;
		next_ugly_index++;
	}

	int ugly = ugly_numbers[index-1];
	free(ugly_numbers);
	return ugly;

}


int min(int number1, int number2, int number3){
	int min_number = number1 < number2 ? number1 : number2;
	min_number = min_number < number3 ? min_number : number3;

	return min_number;
}

/*

output:
Ugly number at 1500 is 859963392
 *
 */
