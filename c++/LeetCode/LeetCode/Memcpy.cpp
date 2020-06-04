#include "Memcpy.h"
#include <cstddef>

/*
	��src��ָ�ڴ濽����dst��ָ�ڴ�
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