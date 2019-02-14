//this program:
//takes input from file
//decodes hex file content with single XOR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myCrypto.h"

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
			}	else if (rankedLows[r] == str[c]) {
				score += r;
			}
		}
	}
	
	return score;
}

void append(char *str, char c) {
	for (; *str; str++); //null for loop to get to end of str
	*str++ = c;
	*str++ = 0;
}

int decryptXOR(char bin[]) {
	static struct ultimate;
	ultimate.score = 0;
	struct outputString outputs[256];
	int key;
	struct outputString highest;
	highest.score = 0;
	for (int x = 0; x < 256; x++) { //x is the char we will XOR against
		for (int i = 0; i < (int)strlen(bin); i+=8) {
			int total = 0; //this will be the ascii equivalent of the binary
			for (int b = 0; b < 8; b++) {
				if (bin[b+i] == '1')
					total += pow(2, 7-b);
			}
			char temp = total^x;
			strcat(outputs[x].string, &temp);
		}
	}

	for (int j = 0; j < 256; j++) {
		outputs[j].score = getScore(outputs[j].string);
		if (outputs[j].score > highest.score) {
			highest = outputs[j];
			key = j;
		}
	}
	
	if (ultimate.score < highest.score) {
		ultimate = highest;
		return key;
	} else {
		return 0;
	}
}

int main( void ) {
	char current_str[256];
	char bin[1024];
	char ch, file_name[25];
	int masterKey, inputLine = 1;
	FILE *fp;

	printf("Name of ciphertext file: ");
	scanf("%s", file_name);

	fp = fopen(file_name, "r"); // read mode

	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
	while((ch = fgetc(fp)) != EOF) {
		if (ch != '\n') {
			append(current_str, ch);
		}	else {
			printf("==%d==\n", inputLine++);
			hexToBin(bin, current_str);
			int temp = decryptXOR(bin);
			if (temp > 0)
				masterKey = temp;
			strcpy(current_str, "");
			strcpy(bin, "");
		}
	}

	fclose(fp);
	
	puts(ultimate.string);
	printf("key: $%d\n", masterKey);
	
	printf("\n");
	
	return 0;
}
