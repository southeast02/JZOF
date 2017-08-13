
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 60

int get_sum(int arr[]);
int get_all(char *str);

int main(){
//输入仅包含A..Z的字符串str，字符串长度不超多50.每个字符代表一种颜色。
//输出满足要求字符串的个数：在str的全排列中找出
//满足不同花色最多存在一对不相邻的排列个数。相同花色的排列视为一种。
//输入ABAB，全排列为：AABB,ABAB, BBAA, BABA, ABBA, BAAB.
//满足要求的排列为：AABB，BBAA。
	char str[N];

	scanf("%s", str);


	printf("%d", get_all(str));
    return 0;
}

int get_all(char *str){
	int count = 0;
	int len = strlen(str);

	int arr[26] = {0};

	for(int i=0; i<len; i++){
		arr[str[i]-'A']=1;
	}

	// only one color
	count = get_sum(arr);
	if(count == 1){
		return 1;
	}
	else if( count == 2){
		return 2;
	}
	return 0;
}

int get_sum(int arr[]){
	int count=0;
	for(int i=0; i<26; i++){
		count += arr[i];
	}
	return count;
}

/*
 * output:
AABA
2
 * */
