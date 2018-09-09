#include "Cadenas.h"

char* quita_espacios ( char *cadena )
	{
		char *aux  = (char* ) malloc ( sizeof (char ) * tam_cad(cadena)) ;
		int i, j ;
		for ( i = 0 , j = 0  ; cadena[ i ] != '\0' ; i++  )
			if ( toascii(cadena[ i ]) != 32 )
				{
					aux[ j ] = cadena[ i ] ;
					j++;
				}	
		aux[j] = '\0' ;	
		cadena = aux ;
		return cadena ;
	}
int tam_cad( char *cadena )
	{
		int i ;
		for ( i = 0 ; cadena[ i ] != '\0' ; i++) ;
		return i ;
	}