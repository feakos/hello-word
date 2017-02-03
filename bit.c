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

	puts("Adj meg egy decimális számot: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	
	number = strtol(buffer, &end, BASE);
		
	if ((errno == ERANGE && (number == LONG_MAX || number == LONG_MIN)) 
		|| (errno != 0 && number == 0)){
    	fprintf(stderr, "Ez sajnos több, mint 64 bit!\n");
    	exit(1);
    }
    else{
		decToBin(number);
	}

	return 0;
}

void decToBin(long int number){
	char maradek[MAX_BITS];
	int i = 0;

	if(number < 0){	
		fprintf(stderr, "Sajnos negativ szamot adtal meg. Holnap visszaterunk ra!\n");
		fprintf(stderr, "De addig is negalom neked %li\n", -number);
/*		number = -number;
		while (number != 0){
			if((number & 1) == 0)
				maradek[i] = '0';
			if((number & 1) == 1)
				maradek[i] = '1';

			number = number >> 1;
			i++;
		}
		maradek[i] = 0;*/
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