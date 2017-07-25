#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int string_add_one(char *number, int last);
int atoi2(char c);
char itoa2(int n);
void output_string_as_int(char *number, int length);


int main(){
    char * arr;
    int N; // bits of integer
    int i=0;

//    scanf("%d", &N);
    N = 2;
    arr = (char *)malloc(sizeof(char) * N);

    while(string_add_one(arr, N)){
    	output_string_as_int(arr, N);
    	i++;
    	if (i % 10 == 0){
    		puts("");
    	}
    }
    return 0;
}


int string_add_one(char *number, int last){

	int jinwei = (atoi2(number[last-1]) + 1) / 10; //get jinwei
	number[last-1] = itoa2((atoi2(number[last-1]) + 1) % 10); // add 1
	last--;

	while(jinwei && last>0){
		jinwei = (atoi2(number[last-1]) + 1) / 10;
		number[last-1] = itoa2((atoi2(number[last-1]) + 1) % 10);
		last--;
	}
	if(last >= 0 && jinwei != 1){
		return 1;
	}
	return 0;
}

int atoi2(char c){
	if (c>= '0' && c<='9'){
		return c-'0';
	}
	return -1;
}

char itoa2(int n){
	if (n >=0 && n<=9){
		return n+'0';
	}
	return '\0';
}

void output_string_as_int(char *number, int length){
	int i=0;
	while(number[i] == '0'){
		i++;
	}

	while(i < length){
		printf("%c", number[i++]);
	}
	printf("\t");
}

/**
 * 	1	2	3	4	5	6	7	8	9
10	11	12	13	14	15	16	17	18	19
20	21	22	23	24	25	26	27	28	29
30	31	32	33	34	35	36	37	38	39
40	41	42	43	44	45	46	47	48	49
50	51	52	53	54	55	56	57	58	59
60	61	62	63	64	65	66	67	68	69
70	71	72	73	74	75	76	77	78	79
80	81	82	83	84	85	86	87	88	89
90	91	92	93	94	95	96	97	98	99
 * */
