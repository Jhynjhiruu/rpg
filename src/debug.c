#include "debug.h"

#include <stdarg.h>

#include "types.h"

#ifdef DEBUG

void dprintf(const char *fmt, ...) {
	va_list ap;
	const char *p;

	va_start(ap, fmt);

	for (p = fmt; *p; ++p) {
		if (*p == '%') {
			switch(*++p) {
				case '%':
					DEBUG_CHAR = '%';
					break;
				case 'c':
					DEBUG_CHAR = va_arg(ap, char);
					break;
				case 's':
					dprint_str(va_arg(ap, char*));
					break;
				case 'x':
					DEBUG_UHEX8 = (u8)va_arg(ap, u16);
					break;
				case 'd': case 'i':
					dprint_sint(va_arg(ap, s16));
					break;
				case 'u':
					dprint_uint(va_arg(ap, u16));
					break;
				// TODO: case 'f'
			}
		}
		else {
			DEBUG_CHAR = *p;
		}
	}
	
	DEBUG_CHAR = '\n';
	
	va_end(ap);
}

void dprint_char(char c){
	DEBUG_CHAR = c;
}

void dprint_str(char *str) {
	char *pntr = str;
	while(*pntr) {
		DEBUG_CHAR = *pntr++;
	}
}

void dprint_byte(unsigned char b) {
	DEBUG_UHEX8 = b;
}

void dprint_uint(unsigned int i) {
	if (i < 256) {
		DEBUG_UINT8 = (unsigned char)i;
	}
	else {
		DEBUG_INT16L = (unsigned char)i;
		DEBUG_UINT16 = (unsigned char)(i >> 8);
	}
}

void dprint_sint(signed int i) {
	if (i < 256) {
		DEBUG_SINT8 = (unsigned char)i;
	}
	else {
		DEBUG_INT16L = (unsigned char)i;
		DEBUG_SINT16 = (unsigned char)(i >> 8);
	}
}

void dprint_ptr(void * p) {
	pointer_t ptr = *(pointer_t *)&p;
	dprint_byte(ptr.bank);
	dprint_byte(ptr.offset >> 8);
	dprint_byte(ptr.offset);
}

#else

void dprintf(const char *fmt, ...) {
	return;
}

void dprint_char(char c){
	return;
}

void dprint_str(char *str) {
	return;
}

void dprint_byte(unsigned char b) {
	return;
}

void dprint_uint(unsigned int i) {
	return;
}

void dprint_sint(signed int i) {
	return;
}

void dprint_ptr(void * p) {
	return;
}

#endif