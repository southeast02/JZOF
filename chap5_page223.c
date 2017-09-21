#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int number_of_1_between_1_and_n(int n);
int number_of_1(char str_n[]);
int power_base_10(unsigned int n);


int main() {

	int n = 12;
	int result = number_of_1_between_1_and_n(n);

	printf("Number of 1 between 1 and %d: %d\n", n, result);
    return 0;

}


int number_of_1_between_1_and_n(int n){
	if(n <= 0){
		return 0;
	}
	char str_n[50];
	sprintf(str_n, "%d", n);
	return number_of_1(str_n);
}


int number_of_1(char str_n[]){
	if(!str_n || *str_n < '0' || *str_n > '9' || *str_n == '\0'){
		return 0;
	}

	int first = *str_n - '0';
	unsigned int length = (unsigned int)strlen(str_n);

	if(length == 1 && first == 0)
		return 0;
	if(length == 1 && first > 0)
		return 1;

	int num_first_digit = 0;
	if(first > 1)
		num_first_digit = power_base_10(length-1);
	else if(first == 1){
		num_first_digit = atoi(str_n + 1) + 1;
	}

	int num_other_digits = first * (length - 1) * power_base_10(length - 2);
	int num_recursive = number_of_1(str_n + 1);

	return num_first_digit + num_other_digits + num_recursive;
}

int power_base_10(unsigned int n){
	int result = 1;
	for(int i=0; i < n; i++)
		result *= 10;

	return result;
}


/*
 * output:
Number of 1 between 1 and 12: 5

 * */
