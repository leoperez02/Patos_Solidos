#include "Colas_dinamicas.h"

void Inicializa_cola ( Cola *cola1)
	{
		(*cola1).longitud = 0 ;
		(*cola1).elementos = NULL ;
	}

char pop ( Cola *cola1)
	{
		if ( !is_empty(cola1))
			{
				char cara =   (*((*cola1).elementos)).valor; 
				int i, j, n = (*cola1).longitud - 1;
				Elemento *array = (Elemento*) malloc ( sizeof(Elemento) * n) ;
				for ( i = 0 , j = 1 ; j < n+1 ; i++ , j++)
					*(array+i) = *(((*cola1).elementos) + j ) ;
				(*cola1).elementos = array ;
				(*cola1).longitud -- ;
				if ( is_empty(cola1))
					printf("\nCola vacia");
				return cara ;
			}
		else
			{
				printf("\n\nCola vacia");
				return ' ' ;
			}
	}

void imprime_cola ( Cola *cola1 ) 
	{
		if ( !is_empty(cola1))
			{
				int i ; 
				for ( i = 0 ; i < (*cola1).longitud  ; i++ )
					printf("%c  ",    (*(((*cola1).elementos)+i)).valor   );
				printf("\n");
			}
		else
			printf("\n\nCola vacia");
	}

void push ( Cola *cola1, char valor )
	{
		int i, n = (*cola1).longitud + 1;
		Elemento un_elemento ;
		un_elemento.valor = valor ;
		if ( is_empty(cola1) )
			{
				(*cola1).elementos = (Elemento*) malloc ( sizeof(Elemento) * n);
				*((*cola1).elementos) = un_elemento ;
			}
		else
			{
				Elemento *array = (Elemento*) malloc ( sizeof(Elemento) * n) ;
				for ( i = 0 ; i < n-1 ; i++ )
					*(array+i) = *(((*cola1).elementos) + i ) ;
				*(array+(n-1)) = un_elemento;
				(*cola1).elementos = array ;
			}
		(*cola1).longitud ++ ;
	}

int is_empty (Cola *cola1)
	{
		if ( (*cola1).longitud == 0 )
			return 1 ;
		else
			return 0 ;
	}