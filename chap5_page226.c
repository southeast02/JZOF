#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int begin_number(int digits);
int digit_at_index_core(int index, int digits);
int count_of_integers(int digits);
int digit_at_index(int index);
int pow_int(int digits);


int main() {

	int n = 5;
	int result = digit_at_index(n);
	printf("Digit at index %d: %d\n", n, result);
    return 0;

}


int digit_at_index(int index){
	if( index < 0){
		return -1;
	}

	int numbers;
	int digits = 1;
	while( 1 ) {
		numbers = count_of_integers(digits);
		if(index < numbers * digits) {
			return digit_at_index_core(index, digits);
		}
		index -= numbers * digits;
		digits++;
	}
	return -1;
}


int count_of_integers(int digits){
	if ( digits == 1){
		return 10;
	}
	int count = pow_int(digits - 1);
	return 9 * count;
}


int digit_at_index_core(int index, int digits){
	int number = begin_number(digits) + index / digits;
	int index_from_right = digits - index % digits;

	for( int i=1; i < index_from_right; i++){
		number /= 10;
	}
	return number % 10;
}

int begin_number(int digits){
	if(digits == 1){
		return 0;
	}
	return pow_int(digits - 1);
}


int pow_int(int digits){
	if( digits < 0){
		return -1;
	}
	if(digits == 0){
		return 0;
	}

	int result = 1;
	for(int i = 0; i < digits; i++){
		result *= 10;
	}
	return result;
}
/*
 * output:

Digit at index 19: 4
Digit at index 12: 1
Digit at index 5: 5


 * */
