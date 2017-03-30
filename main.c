#include <stdio.h>
#include <stdlib.h>

int
main( void )
{
    FILE * Fstrings = fopen( "strings.txt", "r" );
    int n = 2, l = 0, c = 0;
    char** strings = (char**)malloc( n * sizeof(char*) );
    int counts[2];
    while ( fscanf( Fstrings, "%s", strings[l] ) || ( fscanf( Fstrings, "%d", counts[c] ) && c++ < 2 ) )
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