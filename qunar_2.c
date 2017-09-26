#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
}EDGE;


typedef struct {
	int number;
	int weight;
	int visited;
}VERTEX;

int main() {
	int num_of_edge;
	int num_of_vertex;
	EDGE *edge;
	VERTEX *vertex;
	int head, tail;
	VERTEX *que, *que2;
	int *temp;
	int max;
	int index;
	int count;
	int *out;
	int out_count=0;


	scanf("%d%d", &num_of_vertex, &num_of_edge);

	vertex = (VERTEX *)malloc(num_of_vertex * sizeof(VERTEX));
	que = (VERTEX *)malloc(num_of_vertex * sizeof(VERTEX));
	que2 = (VERTEX *)malloc(num_of_vertex * sizeof(VERTEX));
	temp = (int *)malloc(num_of_vertex * sizeof(int));
	out = (int *)malloc(num_of_vertex * sizeof(int));
	edge = (EDGE *)malloc(num_of_edge * sizeof(EDGE));

	for(int i=0; i<num_of_vertex; i++){
		scanf("%d%d", &(vertex[i].number), &(vertex[i].weight));
		vertex[i].number -= 1;
		vertex[i].visited = 0;
	}

	for(int i=0; i<num_of_edge; i++){
		scanf("%d%d", &(edge[i].start), &(edge[i].end));
		edge[i].start -= 1;
		edge[i].end -=1;
	}

	//find entery point
	for(int i=0; i<num_of_vertex; i++){
		temp[i] = 0;
	}
	for(int i=0; i<num_of_edge; i++){
		temp[edge[i].end] = 1;
	}

	tail = head = 0;
	for(int i=0; i<num_of_vertex; i++){
		if(temp[i] != 1){
			que[head].number = i;
			head++;
		}
	}

	count = 0;
	while(count < num_of_vertex){
		int count_local  = 0;
		while(head-tail > count_local){
			max = -1;
			for(int i=0; i<head; i++){
				if(vertex[que[i].number].visited == 0 && vertex[que[i].number].weight > max){
					max = vertex[que[i].number].weight;
					index = que[i].number;
				}
			}

			vertex[index].visited = 1;
			out[out_count++] = index+1;
			count_local++;
		}

		count += count_local;
		count_local = 0;
		for(int j = 0; j < num_of_edge; j++)
			for(int i = tail; i<head; i++){
			{
				if(edge[j].start == que[i].number && vertex[edge[j].end].visited == 0){
					int flag = 0;
					for(int k=0; k<count_local; k++){
						if(que2[k].number == edge[j].end)
							flag = 1;
						break;
					}
					if(!flag)
						que2[count_local++].number = edge[j].end;
				}
			}
		}

		tail = 0;
		head = count_local;
		for(int i=0; i<count_local; i++){
			que[i] = que2[i];
		}
	}

	for(int i=0; i<num_of_vertex; i++){
		printf("%d", out[i]);
		if(i != num_of_vertex-1)
			printf(" ");
	}

	return 0;
}

/*
input
4 4
1 2
2 3
3 5
4 4
1 2
1 3
2 4
3 4

output
1 3 2 4

4 5
1 2
2 8
3 5
4 4
1 2
1 3
1 4
2 4
3 4

output
1 2 3 4

input
1 0
1 2

output
1
 *
 */
