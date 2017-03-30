#include <stdio.h>
#include <stdlib.h>

int
main( void )
{
    // Abrir archivo strings.txt
    FILE * Fstrings = fopen( "strings.txt", "r" );
    if ( !Fstrings )
    {
        printf( "No se encontro el archivo strings.txt" );
        exit( EXIT_FAILURE );
    }
    
    // Declarar e inicializar contadores
    // n = tamanyo del array strings
    // l = linea actual en el archivo ( que corresponda a las string )
    // c = cuantos int ha encontrado
    int n = 2, l = 0, c = 0;
    
    // Declarar el array strings y asignar espacio basico
    char** strings = (char**)malloc( n * sizeof(char*) );
    
    // Declarar el array counts que contiene los ints/contadores del archivo
    int counts[2];
    
    // Procesar el archivo
    while ( fscanf( Fstrings, "%s", strings[l] ) || ( fscanf( Fstrings, "%d", &counts[c] ) && c++ < 2 && l-- ) )
    {
        l++;
        // Verificar si el array tiene espacio suficiente para los proximos elementos
        if ( l == n )
        {
            // Duplicar el espacio del array
            n *= 2;
            strings = (char**)realloc( strings, n * sizeof(char*) );
            // TODO: Evitar el sobrellenado de memoria
        }
    }
    
    // Cerrar el archivo
    fclose( Fstrings );
    
    // Retorno exitoso
    return EXIT_SUCCESS;
}