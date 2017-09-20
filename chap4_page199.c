#include <stdio.h>
#include <stdlib.h>

void print_perm(char arr[], int N, int k, char seq[], int printed[]);


int main() {

	char arr[3] = {'a', 'b', 'c'};
	char seq[4];
	int printed[26] = {0};
	int N = 3;

	print_perm(arr, N, 0, seq, printed);

    return 0;

}



void print_perm(char arr[], int N, int k, char seq[], int printed[]){
	if(k == N){
		seq[k]='\0';
		puts(seq);
		return;
	}
	for(int i=0; i<N; i++){
		if(!printed[arr[i]-'a']){
			printed[arr[i]-'a'] = 1;
			seq[k] = arr[i];
			print_perm(arr, N, k+1, seq, printed);
			printed[arr[i]-'a'] = 0;
		}
	}
}

/*
 * output:
 *
abc
acb
bac
bca
cab
cba


 * */
