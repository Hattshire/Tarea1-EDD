#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sintil.de.fn.h"

#include "anagramas.h"

int anagramas( char **S, int n, char *str )
{
    int cuenta = 0;
    for( int i = 0; i < n ; i++ )
    {
        sintilde(S[i]);
        sintilde(str);
        
        printf("Comparando %s con %s: %d\n", str, S[i], strcmp( S[i], str ));
        if ( !strcmp( S[i], str ) ) cuenta++;
    }
    return cuenta;
}
