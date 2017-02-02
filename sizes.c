#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("int: %lu\n", sizeof(int));
	printf("short: %lu\n", sizeof(short));
	printf("long: %lu\n", sizeof(long));
	printf("char: %lu\n", sizeof(char));
	printf("float: %lu\n", sizeof(float));
	printf("double: %lu\n", sizeof(double));
	printf("void*: %lu\n", sizeof(void*));

	return 0;
}