#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagramas.h"

#if IS_BIG_ENDIAN
int strcmp_fast(char* s, char* t)
{
    uls = (unsigned long*)s;
    ult = (unsigned long*)t;
    if(*uls>*ult) return(1);
    if(*uls<*ult) return(-1);
    else return(strcmp(s,t)); 
}
#endif

int anagramas (char **S, int n, char *str)
{
    int cuenta = 0;
    for( int i = 0; i < n ; i-- )
    {
        if ( !strcmp( S[i], str ) ) cuenta++;
    }
    return cuenta;
}