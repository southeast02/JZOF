/*
 1.what's the problem?
  将一个字符串转换成整数.

 2.how to deal with it?
   1.数有正负
   2.数有溢出
   3.传入指针为空的判断
 */

#include <stdio.h>
#include <string.h>

#define N 100

int EXCEPTION = 0;

int main(){
    char string_1[N] = "-1234";
    char string_2[N] = "+1234";
    char string_3[N] = "";
    char *string_4 = NULL;
    char string_5[N] = "742974374937423904620462046";
    char string_6[N] = "0";
    char string_7[N] = "01234";

    int int_1, int_2, int_3, int_4, int_5, int_6, int_7;

    int_1 = string_to_integer(string_1);
    if (!EXCEPTION){
    	printf("sting %s to integer: %d\n", string_1, int_1);
    }

    int_2 = string_to_integer(string_2);
    if (!EXCEPTION){
    	printf("sting %s to integer: %d\n", string_2, int_2);
    }

    int_3 = string_to_integer(string_3);
    if (!EXCEPTION){
    	 printf("empty sting to integer: %d\n", string_3, int_3);
    }

    int_4 = string_to_integer(string_4);
    if (!EXCEPTION){
    	 printf("sting %s to integer: %d\n", string_4, int_4);
    }

    int_5 = string_to_integer(string_5);
    if (!EXCEPTION){
    	printf("sting %s to integer: %d\n", string_5, int_5);
    }

    int_6 = string_to_integer(string_6);
    if (!EXCEPTION){
    	printf("sting %s to integer: %d\n", string_6, int_6);
    }

    int_7 = string_to_integer(string_7);
    if (!EXCEPTION){
    	printf("sting %s to integer: %d\n", string_7, int_7);
    }
}

int string_to_integer(char *string){
    int number = 0;
    int str_len;
    int i = 0;
    int FLAG = 1;
    int x, y;
    EXCEPTION = 0;

    if (!string || (strlen(string) == 0)){
    	printf("invalid parameter: it's empty!\n");
    	EXCEPTION = 1;
    	return 1;
    }

    str_len = strlen(string);

    if (string[i] == '+'){
    	i++;
    }
    else if (string[i] == '-'){
    	FLAG = -1;
    	i++;
    }
    else if (string[i] == '0' && strlen(string) > 1){
    	printf("invalid parameter: it starts with zero but not zero!\n");
    	EXCEPTION = 1;
    	return 1;
    }

	for(; i < str_len; i++){
		if (string[i] >= '0' && string[i] <= '9'){

			x = number;
			y = string[i] - '0';
			if (FLAG == 1){
				if (x > 0 && y > 0 && (x * 10 + y) < 0 ){
					printf("number is going to overflow.\n");
					EXCEPTION = 1;
					return 1;
				}
			} else if (FLAG == -1){
				x *= FLAG;
				y *= FLAG;
				if (x < 0 && y < 0 && (x * 10  + y) >= 0){
					printf("number is going to overflow.\n");
					EXCEPTION = 1;
					return 1;
				}
			}
			number = number * 10 + (string[i] - '0');
		}
		else{
			printf("Exception: The string %s of number contains "
					"non-integers character %c\n", string, string[i]);
			EXCEPTION = 1;
			return 1;
		}
	}

    number = number * FLAG;
    return number;
}
