#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myCrypto.h"

int main( void ) {
	char hex[256];
	char bin[1024];
	char base64[64];

	for (int i = 0; i < 64; i++) {
		if (i == 63)
			base64[i] = '/';
		else if (i == 62)
			base64[i] = '+';
		else if (i > 51)
			base64[i] = i - 4;
		else if (i > 25)
			base64[i] = i + 71;
		else
			base64[i] = i + 65;
	}
	
	scanf("%s", hex);
	
	hexToBin(bin, hex);
	
	while ((int)strlen(bin) % 6 != 0) {
		for (int i = strlen(bin); i >= 0; i--) {
			bin[i+1] = bin[i];
			bin[i] = '0';
		}
	}

	puts(bin);

	for (int i = 0; i < strlen(bin); i+=6) {
		double total = 0;
		for (int b = 0; b < 6; b++) {
			if (bin[b+i] == '1')
				total += pow(2, 5-b);
		}
		printf("%c", base64[(int)total]);
	}
	
	printf("\n");
	
	return 0;
}
