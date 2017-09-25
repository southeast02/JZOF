#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	// input n: total number of watches
	// t: time left to fix the watches
	// a[n]: time to use to fix each watch
	// output:
	// all number of watches can be fixed within time t
	int total_watches, time_left;
	cin >> total_watches >> time_left;

	int * wathches = (int *)malloc(sizeof(int) * total_watches);
	for(int i = 0; i< total_watches; i++)
		cin >> wathches[i];


	int head = 0, tail = 0, sum = 0, count = 0;

	while(head < total_watches){
		while(sum <= time_left && head < total_watches){
			if(sum + wathches[head] <= time_left)
				sum += wathches[head++];
			else
				break;
		}

		if( (head - tail) > count )
			count = head - tail;

		sum -= wathches[tail++];
	}

	cout << count;

	return 0;
}


//input:
//5 5 
//3 4 5 2 2
//
//output
//2
