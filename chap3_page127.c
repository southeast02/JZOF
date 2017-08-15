#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int match(char * str, char * pattern);
int match_core(char * str, char * pattern);

int main(){
	char *str="ab";
//	char *str="aab";
//	char *str="aaaab";

	char *pattern="a*ab";

	if(match(str, pattern)){
		printf("yes, matches!\n");
	} else{
		printf("no matches!\n");
	}
    return 0;
}


int match(char * str, char * pattern){
	if( str == NULL || pattern == NULL){
		return 0;
	}
	return match_core(str, pattern);
}

int match_core(char * str, char * pattern){
	if(*str=='\0' && *pattern=='\0'){
		return 1;
	}
	if(*str!='\0' && *pattern=='\0'){
		return 0;
	}
	if(*(pattern+1)=='*'){
		if(*str==*pattern ||(*pattern=='.' && *str!='\0')){
			return match_core(str, pattern+2) || //match 0 times
					match_core(str+1, pattern+2) || //match 1 times
					match_core(str+1, pattern); //match multiple times
		}
		else {
			return match_core(str, pattern+2);//match 0 times
		}
	}
	if(*str==*pattern ||(*pattern=='.' && *str!='\0')){
		return match_core(str+1, pattern+1);
	}  else{
		return 0;
	}
}
/**
 * output:
 * yes, matches!
 * */
