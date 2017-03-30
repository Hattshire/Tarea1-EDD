#include <stdio.h>
#include <stdlib.h>
#include "anagramas.h"

#define MAXSTRSIZE 100

int
main( void )
{
    printf ( "Layendo archivo...\n" );
    // Abrir archivo strings.txt
    FILE * Fstrings = fopen ( "strings.txt", "r" );
    // Si el archivo no existe, terminar
    if ( !Fstrings )
    {
        printf ( "No se encontro el archivo strings.txt" );
        exit ( EXIT_FAILURE );
    }
    
    // Declarar e inicializar contadores
    // n = tamanyo del array strings
    // l = linea actual en el archivo ( que corresponda a las string )
    // c = cuantos int ha encontrado
    int n = 2, l = 0, c = 0;
    
    // Declarar el array strings y asignar espacio basico
    char** strings = ( char** ) malloc ( n * sizeof( char* ) );
    
    // Declarar el array counts que contiene los ints/contadores del archivo
    int counts[2];
    
    // Procesar el archivo
    strings[l] = ( char* ) malloc ( MAXSTRSIZE * sizeof( char ));
    while ( 
        !!( fscanf ( Fstrings, "%d\n", &counts[c] ) && c++ <= 2 && (l--)+2 ) ||
         ( fscanf ( Fstrings, "%s\n", strings[l] ) ) )
    {           
        // Verificar si el array tiene espacio suficiente para los proximos elementos
        if ( l == n )
        {
            // Duplicar el espacio del array
            n *= 2;
            strings = ( char** ) realloc ( strings, n * sizeof( char* ) );
            // TODO: Evitar el sobrellenado de memoria
        }
        
        // Si ya se obtubieron los strings a comparar, empezar a compararlos
        if ( c == 2 && l == counts[0] )
        {
            printf ( "\nComparando string %s\n", strings[l] );
            anagramas ( strings, l+1, strings[l] );
        }
        else if ( feof( Fstrings ) ) 
        {
            break;
        }
        else
        {
            if ( l >= 0 )
                printf( "%d, %s", l+1, strings[l] );
            l++;
            strings[l] = ( char* ) malloc ( MAXSTRSIZE * sizeof( char ));
        }
    }
    
    // Cerrar el archivo
    fclose( Fstrings );
    printf( "\nAdios~\n" );
    
    // Retorno exitoso
    return EXIT_SUCCESS;
}
