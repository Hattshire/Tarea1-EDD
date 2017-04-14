#include <stdio.h>
void
sintilde(char* palabra)
{
        printf( "> " );
        for ( int j = 0, k = 0 ;palabra[j] != 0  ; j++, k++ )
        {
            if ( palabra[j] == '\303' )
            {
                k--;
                continue;
            }                
            if ( palabra[j] >= ((char*)"à")[1] &&
                 palabra[j] <= ((char*)"æ")[1] )
                palabra[k] = 'a';
                
            else if ( palabra[j] >= ((char*)"ì")[1] &&
                      palabra[j] <= ((char*)"ï")[1] )
                palabra[k] = 'i';
                
            else if ( palabra[j] >= ((char*)"ù")[1] &&
                      palabra[j] <= ((char*)"ü")[1] )
                palabra[k] = 'u';
                
            else if ( palabra[j] >= ((char*)"è")[1] &&
                      palabra[j] <= ((char*)"ë")[1] )
                palabra[k] = 'e';
                
            else if ( palabra[j] >= ((char*)"ò")[1] &&
                      palabra[j] <= ((char*)"ö")[1] )
                palabra[k] = 'o';
                  
            else if ( palabra[j] >= ((char*)"À")[1] &&
                     palabra[j] <= ((char*)"Ä")[1] )
                palabra[k] = 'a';
            else if ( palabra[j] >= ((char*)"Ì")[1] &&
                      palabra[j] <= ((char*)"Ï")[1] )
                palabra[k] = 'i';
            else if ( palabra[j] >= ((char*)"Ù")[1] &&
                      palabra[j] <= ((char*)"Ü")[1] )
                palabra[k] = 'u';
            else if ( palabra[j] >= ((char*)"È")[1] &&
                      palabra[j] <= ((char*)"Ë")[1] )
                palabra[k] = 'e';
            else if ( palabra[j] >= ((char*)"Ò")[1] &&
                      palabra[j] <= ((char*)"Ö")[1] )
                palabra[k] = 'o';
            else if ( palabra[j] == "ñ"[1] )
                palabra[k] = 'n';
            else if ( palabra[j] == "Ñ"[1] )
                palabra[k] = 'n';
            else palabra[k] = tolower(palabra[j]);
        }
    }