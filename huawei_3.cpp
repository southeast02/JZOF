#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

char get_digit(int n);
int number_to_10(int n, int m);
char *num_to_obj(int num, int m);

int main()
{   // n:source jinzhi
	// m: obj jinzhi
	// ret: obj number
	int t=17;
	char *ret;
	int num;
	int n, m;
	int value;

	cin >> n >> m >>t;
	num = number_to_10(t, n);
	ret = num_to_obj(num, m);
	cout << ret;

	return 0;
}

char get_digit(int n){
	int i=0;
	char sum[62];

	while(i<10){
		sum[i] = char(i+'0');
		i++;
	}

	while(i<36){
		sum[i] = char(i-10+'a');
		i++;
	}

	while(i<62){
		sum[i] = char(i-36+'A');
		i++;
	}
	return sum[n];
}

int number_to_10(int n, int m){
	stack<int> num;
	int m2;
	int sum;
	while(n!=0){
		m2 = n % 10;
		num.push(m2);
		n = n / 10;
	}

	sum=0;
	while(!num.empty()){
		m2 = num.top();
		num.pop();
		sum = sum * m + m2;
	}
	return sum;
}

char *num_to_obj(int num, int m){
	char *arr = (char*)malloc(sizeof(char)*32);
	stack<char> s;
	int j=0;
	int i;
	char ch;

	while(num!=0){
		i = num % m;
		s.push(get_digit(i));
		num = num / m;
	}
	while(!s.empty()){
		ch=s.top();
		s.pop();
		arr[j++] = ch;
	}
	arr[j]= '\0';
	return arr;
}


/**
 * input:
 * 8 16 12345670
 * output:
 * 29cbb8
 * */
