#include "enc.h"
#include <string.h>
#include <cstdio>


int main() {
	char arr[] = "hello there! this is a test string. Pretty cool, eh?";

	unsigned long long int intkey = 0xffffffffffffffc5; // 18446744073709551557 (largest prime that can be stored with 64 bits)
	const char* strkey = "very secret encryption key";

	char* encarr = (char*)SimpleEnc::Tools::Encrypt(arr, sizeof(arr), strkey, strlen(strkey));
	if (!encarr) return 1;

	char* decarr = (char*)SimpleEnc::Tools::Decrypt(encarr, sizeof(arr), strkey, strlen(strkey));
	if (!decarr) {
		free(encarr);
		return 1;
	}

	char* bufs[3] = { arr, encarr, decarr };
	const char* names[3] = { "orginal", "encrpyted", "decrypted" };
	// print bytes of each array in hex
	for (int i = 0; i < 3; ++i) {
		printf("%s:\t{ ", names[i]);
		for (int offset = 0; offset < sizeof(arr); offset += sizeof(unsigned char))
			printf("%02X ", *(unsigned char*)((unsigned long long int)bufs[i] + offset));
		printf("}\n");
	}

	free(encarr);
	free(decarr);

	return 0;
}