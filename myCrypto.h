#include <string.h>

#ifndef MYCRYPT0_H_
#define MYCRYPT0_H_

void hexToBin(char bin[], char hex[]) {
	for (int h = 0; h < (int)strlen(hex); h++) {
		switch (hex[h]) {
			case '0':
				if (h > 0)
					strcat(bin, "0000");
				else 
					strcpy(bin, "0000");
				break;
			case '1':
				if (h > 0)
					strcat(bin, "0001");
				else 
					strcpy(bin, "0001");
				break;
			case '2':
				if (h > 0)
					strcat(bin, "0010");
				else 
					strcpy(bin, "0010");
				break;
			case '3':
				if (h > 0)
					strcat(bin, "0011");
				else 
					strcpy(bin, "0011");
				break;
			case '4':
				if (h > 0)
					strcat(bin, "0100");
				else 
					strcpy(bin, "0100");
				break;
			case '5':
				if (h > 0)
					strcat(bin, "0101");
				else 
					strcpy(bin, "0101");
				break;
			case '6':
				if (h > 0)
					strcat(bin, "0110");
				else 
					strcpy(bin, "0110");
				break;
			case '7':
				if (h > 0)
					strcat(bin, "0111");
				else 
					strcpy(bin, "0111");
				break;
			case '8':
				if (h > 0)
					strcat(bin, "1000");
				else 
					strcpy(bin, "1000");
				break;
			case '9':
				if (h > 0)
					strcat(bin, "1001");
				else 
					strcpy(bin, "1001");
				break;
			case 'a':
				if (h > 0)
					strcat(bin, "1010");
				else 
					strcpy(bin, "1010");
				break;
			case 'b':
				if (h > 0)
					strcat(bin, "1011");
				else 
					strcpy(bin, "1011");
				break;
			case 'c':
				if (h > 0)
					strcat(bin, "1100");
				else 
					strcpy(bin, "1100");
				break;
			case 'd':
				if (h > 0)
					strcat(bin, "1101");
				else 
					strcpy(bin, "1101");
				break;
			case 'e':
				if (h > 0)
					strcat(bin, "1110");
				else 
					strcpy(bin, "1110");
				break;
			case 'f':
				if (h > 0)
					strcat(bin, "1111");
				else 
					strcpy(bin, "1111");
				break;
		}
	}
}

#endif //MYCRYPTO_H_
