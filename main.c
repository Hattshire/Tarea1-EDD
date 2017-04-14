#include <stdio.h>
#include <stdlib.h>

#include "anagramas.h"

#ifndef MAXSTRSIZE
#define MAXSTRSIZE 100
#endif

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
    while ( ( fscanf ( Fstrings, "%d\n", &counts[c] ) && c++ <= 2 && (l--)+2 ) || ( fscanf ( Fstrings, "%s\n", strings[l] ) ) )
    {           
        // Verificar si el array tiene espacio suficiente para los proximos elementos
        if ( l == n )
        {
            // Duplicar el espacio del array
            n *= 2;
            strings = ( char** ) realloc ( strings, n * sizeof( char* ) );
            // TODO: Evitar el sobrellenado de memoria
        }
        
        if (c == 2 && l < counts[0]) // Si se obtubieron los strings a comparar, pero no el de comparacion, alojar espacio
        {
            // Alojar la string de comparacion
            l++;
            strings[l] = ( char* ) malloc ( MAXSTRSIZE * sizeof( char ));
        }
        else if ( c == 2 && l == counts[0] ) // Si ya se obtubieron los strings a comparar, empezar a compararlos
        {
            printf ( "\33[2KComparando string %s", strings[l] );
            anagramas ( strings, l+1, strings[l] );
        }
        else if ( feof( Fstrings ) ) // Si ya no hay mas strings para comparar, dejar de leer el archivo
        {
            break;
        }
        else // Si todavia estamos leyendo strings a comparar, mostrarlas mientras se leen
        {
            if ( l >= 0 ) // Solo si ya leimos el primer contador, mostrar la string leida actualmente
                printf( "\33[2K%d, %s", l+1, strings[l] );
            // Alojar la siguiente string
            l++;
            strings[l] = ( char* ) malloc ( MAXSTRSIZE * sizeof( char ));
        }
    }
    
    // Cerrar el archivo
    fclose( Fstrings );
    printf( "\33[2KAdios~\n" );
    
    // Retorno exitoso
    return EXIT_SUCCESS;
}
