#include <stdio.h>
#include <stdlib.h>

void decToBin(int number);
void decToBin2(int number);

int main(){
	int number;

	puts("Adj meg egy decimális számot: ");
	scanf("%d", &number);
	decToBin(number);
	//decToBin2(number);

	return 0;
}

void decToBin(int number){
	char maradek[20];
	int i = 0;
	
	while (number != 0){
		if((number & 1) == 0)
			maradek[i] = '0';
		if((number & 1) == 1)
			maradek[i] = '1';

		number = number >> 1;
		i++;
	}
	maradek[i] = 0;
	printf("%i\n", i);

	char temp[i + 1];
	int j = 0;
	while(i >= 0){
		temp[j] = maradek[i];
		i--;
		j++;
	}

	for(i = 0; i < sizeof(temp); i++){
		printf("%c", temp[i]);
	}
	printf("\n");

}

void decToBin2(int number){
	char maradek[20];
	int i = 0;
	
	while (number != 0){
		if(number % 2 == 0)
			maradek[i] = '0';
		if(number % 2 == 1)
			maradek[i] = '1';

		number /= 2;
		i++;
	}
	maradek[i] = 0;
	printf("%i\n", i);

	char temp[i + 1];
	int j = 0;
	while(i >= 0){
		temp[j] = maradek[i];
		i--;
		j++;
	}

	for(i = 0; i < sizeof(temp); i++){
		printf("%c", temp[i]);
	}
	printf("\n");
}