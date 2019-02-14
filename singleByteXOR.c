//this program
//takes a hex encoded input
//XORs it with every possible ASCII character
//outputs English plaintext

//ETAOIN SHRDLU are the 12 most frequent letters in the English lang
#include <stdio.h>
#include <math.h>
#include "myCrypto.h"

/*
1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
*/

struct outputString {
	char string[256];
	int score;
};

int getScore(char *str) {
	int score = 0;
	char rankedCaps[27] = "ZQXJKVBPGFYWMCUDLRHSINO ATE";
	char rankedLows[27] = "zqxjkvbpgfywmcudlrhsino ate";
	for (int c = 0; c < (int)strlen(str); c++) {
		for (int r = 0; r < 27; r++) {
			if (rankedCaps[r] == str[c]) {
				score += r;
			}
			else if (rankedLows[r] == str[c]) {
				score += r;
			}
		}
	}
	
	return score;
}

void decryptXOR(char bin[]) {
	struct outputString outputs[256];
	for (int x = 0; x < 256; x++) { //x is the char we will XOR against
		for (int i = 0; i < (int)strlen(bin); i+=8) {
			int total = 0; //this will be the ascii equivalent of the binary
			for (int b = 0; b < 8; b++) {
				if (bin[b+i] == '1')
					total += pow(2, 7-b);
			}
			char temp = total^x;
			strncat(outputs[x].string, &temp, 1);
		}
	}
	
	int key;
	struct outputString highest;
	highest.score = 0;
	for (int j = 0; j < 256; j++) {
		outputs[j].score = getScore(outputs[j].string);
		if (outputs[j].score > highest.score) {
			highest = outputs[j];
			key = j;
		}
	}
	
	printf("key: #%d\n", key);
	puts(highest.string);
}

int main( void ) {
	char hex[256];
	char bin[1024];

	printf("Hex: ");
	scanf("%s", hex);
	hexToBin(bin, hex);
	
	decryptXOR(bin);

	printf("\n");

	return 0;
}
