#include <stdio.h>
#include <stdlib.h>

int
main( void )
{
    FILE * Fstrings = fopen( "strings.txt", "r" );
    int n = 2, l = 0;
    char** strings = (char**)malloc( n * sizeof(char*) );
    while ( fscanf( Fstrings, "%s", strings[l] ) )
    {
        l++;
        if ( l == n )
        {
            n *= 2;
            strings = (char**)realloc( strings, n * sizeof(char*) );
        }
    }
    fclose( Fstrings );
    return EXIT_SUCCESS;
}