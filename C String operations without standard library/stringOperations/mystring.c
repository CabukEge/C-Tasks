#include "mystddef.h"
#include "mystring.h"

size_t mystrlen(char *str) {
    size_t i = 0;
    while (str[i++] != 0); //am Pointer hochzählen bis Nullbyte später -1 wegen Nullbyte returnen
    return i - 1;
}

char *mystrcpy(char *dest, const char *src) {
    size_t i = 0;
    do { dest[i] = src[i]; } while(src[i++] != 0); //scr wird in dest übertragen hierbei hochzählen inklusive Nullbyte
    return dest;
}

char *mystrcat(char *dest, const char *src) {
    mystrcpy(dest + mystrlen(dest), src); //mit mystrcpy an das ende von dest (durch mystrenlen) src anhängen
    return dest;
}

int mystrcmp(const char *s1, const char *s2) {
    unsigned char s1v;
    unsigned char s2v;
     
    do {
        s1v = *s1++; //Pointer hochzählen währenddessen char vergleichen
        s2v = *s2++;

        if (s1v > s2v) return 1; //3 mögliche ausgangspositionen
        if (s1v < s2v) return -1;
    } while((s1v | s2v) != 0); //logisches oder um zu erkennen, wenn beide strings identisch sind und somit gleichzeitig ihr nullbyte erreichen

    return 0;
}

void *mymemcpy(void *dest, const void *src, size_t n) {
    for (size_t i = 0; i < n; i++) ((char *) dest)[i] = ((char *) src)[i]; //dest und src als char* casten, ab da wie strcpy nur n mal statt bis nullbyte
    return dest;
}

void *mymemset(void *buf, int ch, size_t n) {
    for (size_t i = 0; i < n; i++) ((char *) buf)[i] = (char) ch; //ähnlich wie zuvor ch wird als char interpretiert da es vorher ein int war, sonst selber ablauf
    return buf;
}
