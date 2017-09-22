#include <stdio.h>
#include <string.h>


int longest_substring_without_duplication(char arr[], int str_len);


int main(int argc,char**argv){

	char arr[] = "arabcacvfr";
	int str_len = strlen(arr);
	int max_length;

	max_length = longest_substring_without_duplication(arr, str_len);
	printf("Max length of substring is: %d \n", max_length);
	return 1;
}


int longest_substring_without_duplication(char arr[], int str_len){
	int position[26];
	int last_length;
	int current_length;
	int max_length = -1;
	int dist;

	for(int i = 0; i < 26; i++)
		position[i] = -1;

	last_length = 1;
	position[arr[0] - 'a'] = 0;
	for(int i = 1; i < str_len; i++){
		if(position[arr[i] - 'a'] == -1){
			current_length = last_length + 1;
		} else {
			dist = i - position[arr[i] - 'a'];
			if(dist > last_length){
				current_length = last_length + 1;
			} else{
				current_length = dist;
			}
		}

		position[arr[i] - 'a'] = i;
		last_length = current_length;

		if(current_length > max_length){
			max_length = current_length;
		}

	}
	return max_length;

}

// output
//
// Max length of substring is: 5
