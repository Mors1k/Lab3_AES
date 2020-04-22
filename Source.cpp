using namespace std;
#include <iostream>
#include "AES.h"

int main() {
	unsigned char plain[] = { 0x4d, 0x6f, 0x72, 0x67, 0x75, 0x6e, 0x6f, 0x76, 0x20, 0x44, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 }; //plaintext example
	unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
	unsigned int plainLen = 16 * sizeof(unsigned char);  //bytes in plaintext
	unsigned int outLen = 0;  // out param - bytes in ñiphertext

	AES aes(128);  //128 - key length, can be 128, 192 or 256
	unsigned char * c = aes.EncryptECB(plain, plainLen, key, outLen);
	cout << c << endl;
	cout << "---" << endl;
	unsigned char * d = aes.DecryptECB(c, plainLen, key);
	cout << d<<endl;
	cout << "---" << endl;

	system("pause");
	return 0;
}