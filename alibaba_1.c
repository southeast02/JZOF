/**
 *
1. 猎人把一对兔子婴儿(一公一母称为一对)放到一个荒岛上，两年之后，它们生下一对小兔，之后开始每年都会生下一对小兔。生下的小兔又会以同样的方式继续繁殖。
2. 兔子的寿命都是x(x>=3)年，并且生命的最后一年不繁殖。
3. 如果岛上的兔子多于10对，那么猎人会每年在兔子们完成繁殖或者仙逝之后，从岛上带走两对最老的兔子。
请问y年(y>=3)后荒岛上所有的兔子加起来多少岁?(注意, 在条件3执行完之后)

输入: 从命令行输入两行整数，第一行是x，第二行是y
输出: y年后荒岛上所有的兔子岁数的总和

请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
x //兔子的寿命 y //若干年以后
输出:
n //所有兔子的年龄之和
输入范例:
3
3
输出范例:
2
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_all_ages(int x, int y);

int main(){

	int x=3;
	int y=5;
	int sum_age;

	scanf("%d%d", &x, &y);

	sum_age = get_all_ages(x, y);

	printf("all rabbits ages = %d\n", sum_age);
    return 0;
}

int get_all_ages(int x, int y){
	int *age;
	int count;
	int total;
	int i, j;
	int sum_age=0;

	age = (int *)malloc(sizeof(int)*(x+1));

	age[0]=1;
	total=1;
	for(i=1; i<=x; i++){ //只有新生的兔子
		age[i]=0;
	}

	for(i=1; i<=y; i++){ //若干年后

		for(j=x; j>0; j--){ //兔子长大一岁
			age[j]=age[j-1];
		}

		age[0]=0;
		for(j=2; j<=x-1; j++){//兔子繁殖
			age[0]+=age[j];
		}
		total += age[0]; //兔子总数改变

		age[x]=0;//兔子死

		if(total>10){//带走兔子
			count=2;
			int age_j;
			for(j=x-1; j>=0; j--){
				age_j = age[j];
				if(age_j-count >= 0){
					age[j] -= count;
					break;
				} else{
					count -= age_j;
					age[j] = 0;
				}
			}
		}
	}

	for(i=1; i<=x; i++){
		sum_age += age[i] * i;
	}
	sum_age *= 2;

	return sum_age;
}
