#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "myCrypto.h"

int main( void ) {
	char hexadecimal[16];
	for (int i = 0; i < 16; i++) {
		if (i < 10)
			hexadecimal[i] = i + 48;
		else
			hexadecimal[i] = i + 87;
	}
	
	char hex1[256];
	char hex2[256];
	char bin1[1024];
	char bin2[1024];
	
	printf("Hex1: ");
	scanf("%s", hex1);
	hexToBin(bin1, hex1);
	printf("Hex2: ");
	scanf("%s", hex2);
	hexToBin(bin2, hex2);
	
	char *binResult = malloc(sizeof(char) * (int)strlen(bin1));
	
	for (int i = 0; i < (int)strlen(bin1); i++) {
		int bit1 = bin1[i] - 48;
		int bit2 = bin2[i] - 48;
		binResult[i] = (bit1^bit2) + 48;
	}
	
	printf("%d\n", (int)strlen(binResult));
	
	printf("xXOR: ");
	
	for (int i = 0; i < (int)strlen(binResult); i+=4) {
		double total = 0;
		for (int b = 0; b < 4; b++) {
			if (binResult[b+i] == '1')
				total += pow(2, 3-b);
		}
		printf("%c", hexadecimal[(int)total]);
	}
	
	printf("\n");
	
	return 0;
}
