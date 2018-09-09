#include "Recorridos_Arboles.h"

void Pre_Orden ( Arbol *Arbolito ) 
	{
		if (  !es_vacio(Arbolito)  )
			{
				printf("%c ",  (*((*Arbolito).Raiz)).Nombre   ) ;
				if (   (*Arbolito).Hijo_izquierdo != NULL )
					Pre_Orden ((*Arbolito).Hijo_izquierdo) ; 
				if (  (*Arbolito).Hijo_derecho != NULL)
					Pre_Orden ((*Arbolito).Hijo_derecho) ; 
			}
		else
			printf("\n\nArbol vacio\n");
	}
	
void In_Orden ( Arbol *Arbolito ) 
	{
		if ( !es_vacio(Arbolito) )
			{
				if (   (*Arbolito).Hijo_izquierdo != NULL )
					{
						In_Orden ((*Arbolito).Hijo_izquierdo) ;
						printf("%c ",  (*((*Arbolito).Raiz)).Nombre   ) ;
						if (  (*Arbolito).Hijo_derecho != NULL )
							In_Orden ((*Arbolito).Hijo_derecho) ;
					}
				else
					{
						printf("%c ",  (*((*Arbolito).Raiz)).Nombre   ) ;
						if (  (*Arbolito).Hijo_derecho != NULL )
							In_Orden ((*Arbolito).Hijo_derecho) ;
					}
			}
		else
			printf("\n\nArbol vacio\n\n");
	}
	
void Post_Orden ( Arbol *Arbolito ) 
	{
		if ( !es_vacio(Arbolito) )
			{
				if ( (*Arbolito).Hijo_izquierdo != NULL )
					Post_Orden ( (*Arbolito).Hijo_izquierdo ) ;
				if ( (*Arbolito).Hijo_derecho != NULL )
					{
						Post_Orden ( (*Arbolito).Hijo_derecho ) ;			
						printf("%c " , (*((*Arbolito).Raiz )).Nombre  );
					}			
				if ( (*Arbolito).Hijo_derecho == NULL )
					printf("%c " , (*((*Arbolito).Raiz )).Nombre  );
			}
		else
			printf("\n\nArbol vacio\n");
	}