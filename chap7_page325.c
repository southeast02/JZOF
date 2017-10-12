#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int atoi_2(const char *str);


int exception=0;

int main() {
	int result;
	char str[199];

	scanf("%s", str);

	result = atoi_2(str);
	if(exception == 0){
		printf("str(%s) = %d\n", str, result);
	} else {
		if(exception == -1){
			printf("wrong input: %s\n", str);
		} else {
			printf("overflow!\n");
		}
	}
	return 0;
}


int atoi_2(const char *str){
	int flag = 1;
	long long result = 0; // here result should be long long
	int str_len = strlen(str);
	int i=0;

	if(str_len == 0){
		exception=-1; // null string
		return result;
	} else if(str_len > 11){
		exception=-2;
		return result;
	}
	if(str[i] == '+'){
		flag = 1;
		i++;
		if(str_len == 1){ // only has +/- in str
			exception=-1;
			return result;
		}
	} else if( str[i] == '-'){
		flag = -1;
		i++;
		if(str_len == 1){
			exception=-1;
			return result;
		}
	}

	while(i < str_len){
		if(str[i]>= '0' && str[i]<= '9'){ // non digit
			if(flag == 1 && (result * 10 + (str[i] - '0'))<= INT_MAX){
				result = result * 10 + (str[i] - '0');
				i++;
			} else if (flag == -1 && flag*(result * 10 + (str[i] - '0'))>= INT_MIN){
				result = result * 10 + (str[i] - '0');
				i++;
			}
			else {
				exception = -2;//overflow
				return result;
			}

		} else {
			exception = -1;
			return result;
		}
	}
	return result*flag;
}

// output:

//-2147483649
//overflow!
