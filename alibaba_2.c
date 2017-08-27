#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_DICT_LEN 255
#define MAX_STR 255

typedef struct simple_str {
    const char * str;
    int len;
} simple_str_t;

typedef struct simple_int {
    int split[MAX_DICT_LEN];
    int split_help[MAX_DICT_LEN];
    int split_help_len;
    int split_len;
} simple_int;

int startswith(const char *str, const char *head, int len);
void match(simple_str_t* str, simple_str_t* dict, int dict_len, simple_int* sp);

int startswith(const char *str, const char *head, int len){
     int i=0;
     if(str==NULL || head==NULL || len<=0){
    	 return 0;
     }
     while(i<len && str[i]==head[i]){
         i++;
     }

     if(i==len){
           return 1;
     }
     return 0;
}

void match(simple_str_t* str, simple_str_t* dict, int dict_len, simple_int* sp){
	int find_one_match=0;
	int temp_split_help_len;
	int temp_str_len;
	int i;

	// find a match: arrive at the end of str
	if(str->len == 0){
		if(sp->split_help_len < sp->split_len){
			sp->split_len = sp->split_help_len;
			for(int j=0; j<sp->split_len; j++){
				sp->split[j]=sp->split_help[j];
			}
		}
		return;
	}

	for(i=0; i<dict_len; i++){
		// match head part of str
		if(startswith(str->str+strlen(str->str)-str->len,
				dict[i].str, dict[i].len)){
			temp_split_help_len = sp->split_help_len;
			temp_str_len = str->len;

			sp->split_help[sp->split_help_len++]=i;
			str->len -=dict[i].len;

		    // match left part of str
			match(str, dict, dict_len, sp);
			sp->split_help_len = temp_split_help_len;
			str->len = temp_str_len;
//			if(find_one_match){
////				if(sp->split_help_len < sp->split_len){
////					sp->split_len = sp->split_help_len;
////					for(int j=0; j<sp->split_len; j++){
////						sp->split[j]=sp->split_help[j];
////					}
////				}
//				str->len=temp_str_len;
//				sp->split_help_len = temp_split_help_len;
//			}else
//			{
//				sp->split_help_len = temp_split_help_len;
//				str->len = temp_str_len;
//			}
		}
	}
	return;
}

void mincut(simple_str_t* str, simple_str_t* dict, int dict_len) {
	 simple_int sp;
	 sp.split_len=MAX_DICT_LEN;
	 sp.split_help_len=0;
     int i;

     if(str==NULL || dict==NULL || dict_len<=0){
    	 puts("1 n/a");
    	 return;
     }
     match(str, dict, dict_len, &sp);
     if(sp.split_len!=MAX_DICT_LEN){
    	 for(i=0; i<sp.split_len; i++){
			  printf("%s ", dict[sp.split[i]].str);
    	 }
     } else{
    	 puts("2 n/a");
     }
}

int main(int argc, const char * argv[]) {
    char strS[MAX_STR];
    char dictStr[MAX_STR];
    int nDict;
    simple_str_t dict[MAX_DICT_LEN];
    simple_str_t srcStr;

    scanf("%s", strS);
    scanf("%d", &nDict);

    srcStr.str = strdup(strS);
    srcStr.len = strlen(strS);

    for (int i = 0; i < nDict; i++)
    {
        scanf("%s", strS);
        dict[i].str = strdup(strS);
        dict[i].len = strlen(strS);
    }

    mincut(&srcStr, dict, nDict);

    return 0;
}
/**
input:
helloworldworld
4
hello
world
worldworld
helloworld

output:
hello worldworld

input:
helloworldworld
4
helloworld
world
worldworld
w

output:
helloworld world

input:
cabab
4
cab
ab
c
abab

output:
cab ab 
 * */
