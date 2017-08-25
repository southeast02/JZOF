
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_num(char *str, int N);
int is_integer(char *str, int N);
int is_floating(char *str, int N);
int is_scientific(char *str, int N);

int main(){
	char str[100];

	while(scanf("%s", str)==1){
		if(is_num(str, strlen(str))){
			printf("%s is a number\n", str);
		} else {
			printf("%s is not a number\n", str);
		}
	}
		return 1;
}

int is_num(char *str, int N){
	if(N <= 0){
		return 0;
	}
	if(is_integer(str, N) || is_floating(str, N) || is_scientific(str, N)){
		return 1;
	}
	return 0;
}

int is_integer(char *str, int N){
	int i=0;

	if(N <=0 ){
			return 0;
	}
	// if str[0]==+/-
	if(str[0]=='+' || str[0]=='-'){
		i++;
	}

	// if str[i]=='0'
	if(str[i]=='0'){
		return 0;
	}

	while(i < N){
		if(str[i]>= '0' && str[i]<='9'){
			i++;
		} else{
			return 0;
		}
	}
	return 1;
}

int is_floating(char *str, int N){
	int i=0, k;

	if(N <=0 ){
		return 0;
	}

	// str[0]==+/-
	if(str[0]=='+' || str[0]=='-'){
		i++;
	}

	//str[k]=='.'
	k=i;
	while(k < N){
		if(str[k]=='.'){
			break;
		} else{
			k++;
		}
	}
	if(k==N-1){
		return 0;
	}

	//+/-.345
	if(k == i){
		i++;
		while(i<N){
			if(str[i]>='0' && str[i]<= '9'){
				i++;
			}else{
				return 0;
			}
		}
		return 1;
	}

	//+/-0.345
	if(str[i]=='0' && (i+1==k)){
		i+=2;
		while(i<N){
			if(str[i]>='0' && str[i]<= '9'){
				i++;
			}else{
				return 0;
			}
		}
		return 1;
	}

	//+/-345.345
	if(is_integer(str, k)){
		i=k+1;
		while(i<N){
			if(str[i]>='0' && str[i]<= '9'){
				i++;
			}else{
				return 0;
			}
		}
		return 1;
	} else{
		return 0;
	}
}

int is_scientific(char *str, int N){
	// fine str[k]='e' || str[k]=='E'
	int k=0;
	if(N <=0 ){
		return 0;
	}

	while(k < N){
		if(str[k]=='E' || str[k]=='e'){
			break;
		}else {
			k++;
		}
	}
	if(k==N-1){
		return 0;
	}
	if(is_floating(str, k) && is_integer(str+k+1, N-k-1)){
		return 1;
	} else{
		return 0;
	}
}

/**
 +100
+100 is a number

5e2
5e2 is a number

-123
-123 is a number

4.1234
4.1234 is a number

-1E-16
-1E-16 is a number

12e
12e is not a number

1a3.14
1a3.14 is not a number

1.1.2
1.1.2 is not a number

+-3
+-3 is not a number

12e+5.2
12e+5.2 is not a number

 * */
