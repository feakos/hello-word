#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

void decToBin(long int number);

#define MAX_BITS 64
#define BUFFER_SIZE 128
#define BASE 10

int main(){
	long number;
	char *end, buffer[BUFFER_SIZE];
	errno = 0;

	fprintf(stdout, "Adj meg egy maximum 64 bites decimális számot: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	
	number = strtol(buffer, &end, BASE);
		
	if ((errno == ERANGE && (number == LONG_MAX || number == LONG_MIN)) 
		|| (errno != 0 && number == 0)){
    	fprintf(stderr, "Ez sajnos több, mint 64 bit!\n");
    	exit(EXIT_FAILURE);
    }
    
    if(end == buffer){
    	fprintf(stderr, "Nincsenek benne számok!\n");
    	exit(EXIT_FAILURE);
    }
    
    decToBin(number);
/*	
	if(*end != '\0'){
    	printf("Ezek nem számok: %s\n", end);
    	exit(EXIT_SUCCESS);
    }
*/
	return 0;
}

void decToBin(long int number){
	char maradek[MAX_BITS + 1];
	int i = 0;

	if(number < 0){	
		fprintf(stderr, "Sajnos negatív számot adtál meg. Később visszatérünk rá!\n");
		fprintf(stderr, "De addig is negálom neked %li\n", -number);
	}
	else{
		while (number != 0){
			if((number & 1) == 0)
				maradek[i] = '0';
			if((number & 1) == 1)
				maradek[i] = '1';

			number = number >> 1;
			i++;
		}
		maradek[i] = 0;
		
		char temp[i + 1];
		int j = 0;
		while(i >= 0){
			temp[j] = maradek[i];
			i--;
			j++;
		}

		for(i = 0; i < sizeof(temp); i++){
			fprintf(stdout, "%c", temp[i]);
		}
		fprintf(stdout, "\n");
	}

}