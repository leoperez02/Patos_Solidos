#include "Pila_Char.h"
int is_empty ( char pila_c[ ] )  
	{
		if ( pila_c[0] == '\0' )
			return 1 ;
		else
			return 0 ;
	}
char top ( char pila_c[ ] )
	{
		int i ;
		for ( i = 0 ; pila_c[ i ] != '\0' ; i++ ) ; 
		return pila_c[ i - 1] ;
	}
char pop ( char pila_c[ ] )
		{
			int i ;
			char c ;
			for ( i = 0 ; pila_c[ i ] != '\0' ; i++ ) ; 
			c = pila_c[ i - 1] ;
			pila_c[ i - 1] = '\0' ;
			return c ;
		}
void push ( char pila_c[ ] , char c ) 
	{
		int i ;
		for ( i = 0 ; pila_c[ i ] != '\0' ; i++ ) ; 
		pila_c[ i ] = c ;
		pila_c[ i+1 ] =  '\0' ;
	}