#include "Memcpy.h"
#include <cstddef>

/*
	将src所指内存拷贝到dst所指内存
*/
void MyMemcpy(void* dst, void* src, int len) {
	if (NULL == dst || NULL == src) {
		return;
	}
	while (len--) {
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
}