#include <stdio.h>
#include <ctype.h>
void
sintilde(char* palabra)
{
    int j = 0, k = 0;
    for ( ;palabra[j] != 0  ; j++, k++ )
    {
        if ( palabra[j] == '\303' )
        {
            k--;
            continue;
        }
        if ( palabra[j] >= "à"[1] &&
             palabra[j] <= "æ"[1] )
            palabra[k] = 'a';
            
        else if ( palabra[j] >= "ì"[1] &&
                  palabra[j] <= "ï"[1] )
            palabra[k] = 'i';
            
        else if ( palabra[j] >= "ù"[1] &&
                  palabra[j] <= "ü"[1] )
            palabra[k] = 'u';
            
        else if ( palabra[j] >= "è"[1] &&
                  palabra[j] <= "ë"[1] )
            palabra[k] = 'e';
            
        else if ( palabra[j] >= "ò"[1] &&
                  palabra[j] <= "ö"[1] )
            palabra[k] = 'o';
              
        else if ( palabra[j] >= "À"[1] &&
                 palabra[j] <= "Ä"[1] )
            palabra[k] = 'a';
        else if ( palabra[j] >= "Ì"[1] &&
                  palabra[j] <= "Ï"[1] )
            palabra[k] = 'i';
        else if ( palabra[j] >= "Ù"[1] &&
                  palabra[j] <= "Ü"[1] )
            palabra[k] = 'u';
        else if ( palabra[j] >= "È"[1] &&
                  palabra[j] <= "Ë"[1] )
            palabra[k] = 'e';
        else if ( palabra[j] >= "Ò"[1] &&
                  palabra[j] <= "Ö"[1] )
            palabra[k] = 'o';
        else if ( palabra[j] == "ñ"[1] )
            palabra[k] = 'n';
        else if ( palabra[j] == "Ñ"[1] )
            palabra[k] = 'n';
        else palabra[k] = tolower(palabra[j]);
    }
    palabra[k] = 0;
}
