#include <stdio.h>
#include <string.h>

char matrix[3][4]= {
		{'e', 'b', 'e', 'g'},
		{'c', 'f', 'c', 's'},
		{'e', 'd', 'e', 'h'}
};


char path[] = {'b', 'f', 'c', 'e'};
int visit[3][4];
int row = 3;
int col = 4;
int find_in_path(int index, int x, int y);
void find();
void print_path();

int main(){
	find();
}

void find(){
	int i, j;

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			find_in_path(0, i, j);
		}
	}
}

int find_in_path(int index, int x, int y){
	int ret1, ret2, ret3, ret4;

	if(matrix[x][y] == path[index]){
		visit[x][y] = 1;

		if(index == 3){
			print_path();
			visit[x][y] = 0;
			return 1;
		}

		if(x-1>=0 && visit[x-1][y] != 1) ret1=find_in_path(index+1, x-1, y); else ret1=0;
		if(x+1<row && visit[x+1][y] != 1) ret2=find_in_path(index+1, x+1, y); else ret2=0;
		if(y-1>=0 && visit[x][y-1] != 1) ret3=find_in_path(index+1, x, y-1); else ret3=0;
		if(y+1<col && visit[x][y+1] != 1) ret4=find_in_path(index+1, x, y+1); else ret4=0;

		visit[x][y] = 0; // for there are other paths

		if((ret1 || ret2 || ret3 || ret4)){
			return 1;
		}
	}
	return 0;
}

void print_path(){
	int i, j;

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(visit[i][j])
				printf("%c\t", '*');
			else
				printf("%c\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

/**
 * output:
 
*	*	e	g	
*	*	c	s	
e	d	e	h	

e	*	e	g	
*	*	c	s	
*	d	e	h	

e	*	*	g	
c	*	*	s	
e	d	e	h	

e	*	e	g	
c	*	*	s	
e	d	*	h
 * */

