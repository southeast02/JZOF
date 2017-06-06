#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * change_space_to_special_num(char *str);
void change_space_to_special_num_2(char *str);
void change_space_to_special_num_3(char *str);

#define N 100


int main(){
	char src_str[N]; // need enough empty space to move forward.
	char *dest_str = NULL;

	src_str[0] = 'w';
	src_str[1] = ' ';
	src_str[2] = 'r';
	src_str[3] = ' ';
	src_str[4] = 'e';
	src_str[5] = '\0';


    //dest_str = change_space_to_special_num(src_str);
    //puts(dest_str);

    //change_space_to_special_num_2(src_str);
    //puts(src_str);

	change_space_to_special_num_3(src_str);
	puts(src_str);

	return 0;
}

void change_space_to_special_num_3(char *str){
	int len = strlen(str);
	int n = 0;
	int i, j;

	for(i=0; i<len; i++){
		if(str[i] == ' '){
			n++;
		}
	}

	i = len;
	j = len + n * 2; // new string length

	while(i>=0 && j>i){ // str[len] is '\0'.
		if(str[i] != ' '){
			str[j--] = str[i];
		} else {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		i--;
	}
}


void change_space_to_special_num_2(char *str){
	int len = strlen(str);
	int n = 0;

	for(int i=0; i<len; i++){
		if(str[i] == ' '){
			n++;
		}
	}

	for(int i=len; i>=0 && n>0; i--){ // str[len] is '\0'.
		if(str[i] != ' '){
			str[i + n*2] = str[i];
		} else {
			str[i + n*2] = '0';
			str[i + n*2 -1] = '2';
			str[i + n*2 -2] = '%';
			n--;
		}
	}
}

char * change_space_to_special_num(char *str){
	int len = strlen(str);
	char *dest_str = NULL;
	int j = 0;

	dest_str = (char *)malloc(sizeof(char) * len * 3);

	if(!dest_str){
		return NULL;
	}

	for(int i=0; i<len; i++){
		if(str[i] != ' '){
			dest_str[j++] = str[i]; // remember j plus 1 after used.
		} else {
			dest_str[j++] = '%'; // remember j plus 1 after used.
			dest_str[j++] = '2'; // remember j plus 1 after used.
			dest_str[j++] = '0'; // remember j plus 1 after used.
		}
	}
	dest_str[j]= '\0';

	return dest_str;
}

/**
 * output:
 * w%20r%20e
 * */
