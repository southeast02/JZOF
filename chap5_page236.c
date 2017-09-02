#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

 int main()
{
	printf("INT_MAX: %d\n", 0x7FFFFFFF);
	printf("INT_MAX: %d\n", INT_MAX);

	puts("");
	printf("INT_MAX: %d\n", 0x80000000);
	printf("INT_MAX: %d\n", INT_MIN);
	return 0;
}


/**
 * output:
INT_MAX: 2147483647
INT_MAX: 2147483647

INT_MAX: -2147483648
INT_MAX: -2147483648

 * */
