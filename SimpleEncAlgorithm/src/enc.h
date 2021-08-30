#ifndef _SIMPLE_XOR_ENCRYPTION_H
#define _SIMPLE_XOR_ENCRYPTION_H
#include <malloc.h>

namespace SimpleEnc {
	static class Tools {
	private:
		typedef unsigned long long int uint;
		typedef unsigned char ubyte;
	public:
		// uses simple xor encryption
		static void* Encrypt(const void* data, uint size, const void* key, uint keysize) {
			// validate
			if (!(data && key && size > 0 && keysize > 0)) return nullptr;
			// allocate
			void* output = malloc(size);
			if (!output) return nullptr;
			// xor
			for (uint offset = 0; offset < size; offset += sizeof(ubyte))
				*(ubyte*)((uint)output + offset) = *(ubyte*)((uint)data + offset) ^ *(ubyte*)((uint)key + offset % keysize);
			// done
			return output;
		}

		// uses simple xor encryption
		static void* Decrypt(const void* data, uint size, const void* key, uint keysize) {
			// only uses xor, so enc function is same as dec function
			return Encrypt(data, size, key, keysize);
		}
	};
}
#endif