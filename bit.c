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
	char *end = NULL, buffer[BUFFER_SIZE];
	errno = 0;
	
	fprintf(stderr, "Adj meg egy maximum 64 bites decimális számot: ");
	while(fgets(buffer, BUFFER_SIZE, stdin) != NULL){

		number = strtol(buffer, &end, BASE);
		
		if ((errno == ERANGE && (number == LONG_MAX || number == LONG_MIN)) 
			|| (errno != 0 && number == 0)){
	    	fprintf(stderr, "Ez sajnos több, mint 64 bit!\n");
	    	continue;
    	}
    
	    if(end == buffer){
    		fprintf(stderr, "Nincsenek benne számok!\n");
    		continue;
    	}

	    decToBin(number);

    }
/*
    if((end != NULL) && (*end != '\0')){
    	fprintf(stderr, "Az input nem szám!\n");
    	exit(EXIT_FAILURE);
    }
    
	unsigned long out = 0;
	char* input = valahoval...;
	char* err_ptr = NULL;
	out = strtoul(input, &err_ptr; 10);
	if((err_ptr != NULL) && (*cp_err != '\0')) {
  		//hibakezelés, az input nem egy szám...
	}
*/

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

	unsigned long numberU;

	if(number == 0){
		printf("0\n");
	}

	if(number < 0){	
		numberU = -number; //Negatív számoknál unsigned legyen, különben nem lesz jó.

		numberU = ~numberU;
		numberU = numberU + 0b1;

		while (numberU != 0){
			if((numberU & 1) == 0)
				maradek[i] = '0';
			if((numberU & 1) == 1)
				maradek[i] = '1';
			numberU = numberU >> 1;

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