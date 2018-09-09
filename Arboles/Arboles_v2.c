#include "Arboles_v2.h"

// Funciones estándar .... 	
	
void Sembrar ( Arbol  *Arbolito ) 
	{	
		(*Arbolito).Hijo_izquierdo= ( Arbol* ) malloc ( sizeof ( Arbol ) ) ;
		(*Arbolito).Hijo_derecho  = ( Arbol* ) malloc ( sizeof ( Arbol ) ) ;
		(*Arbolito).Hijo_izquierdo = NULL ;
		(*Arbolito).Hijo_derecho = NULL ;
		(*Arbolito).Raiz = (Nodo*) malloc (sizeof (Nodo)) ;
		(*((*Arbolito).Raiz)).Nombre = ' ' ;
		(*((*Arbolito).Raiz)).Indice = 0 ;
	}

void Talar ( Arbol *Arbolito ) 
	{
		free(Arbolito);
	}
	
int es_vacio ( Arbol *Arbolito ) 
	{	
		if ( (*Arbolito).Hijo_izquierdo == NULL && (*Arbolito).Hijo_derecho == NULL && (*((*Arbolito).Raiz)).Nombre == ' ' )
			return 1 ;
		else
			return 0 ;
	}
	
Nodo* Ver_Raiz ( Arbol *Arbolito )
	{
		if ( es_vacio ( Arbolito ) )
			return NULL ;
		else
			return (*Arbolito).Raiz ;
	}

void Nuevo_hijo ( Arbol *Arbolito , Nodo *nodo_bebe )
	{
			if ( es_vacio ( Arbolito ) )
				(*Arbolito).Raiz = nodo_bebe ;
			else		//Busca menor, compara con raiz y repite el proceso hasta hallar espacio para insertarse 
				{		//	Si es menor, se toma al hijo izquierdo del arbol principal y se considera raiz y se repite el proceso hasta hallar un nodo hoja
					if (  toascii((*nodo_bebe).Nombre) < toascii((*((*Arbolito).Raiz)).Nombre)  )
						{
							if (  (*Arbolito).Hijo_izquierdo == NULL ) 
								{
									// No hay hijo izquierdo, se siembra el arbol hijo izquierdo y se agrega nuevo hijo (nodo_bebe) que entra como raiz del izquierdo
									(*Arbolito).Hijo_izquierdo  = ( Arbol* ) malloc ( sizeof ( Arbol  ) ) ;
									Sembrar ( (*Arbolito).Hijo_izquierdo ) ;
									Nuevo_hijo ( (*Arbolito).Hijo_izquierdo , nodo_bebe ) ;
								}
							else  	// Si hay hijo izquierdo se vuelve al paso de la comparacion tomandolo como raiz
								Nuevo_hijo ( (*Arbolito).Hijo_izquierdo , nodo_bebe ) ;
						}
					else
						{
							//va a la derecha ....
							if (  (*Arbolito).Hijo_derecho == NULL ) 
								{// No hay hijo derecho, se siembra el arbol hijo derecho y se agrega nuevo hijo (nodo_bebe) que entra como raiz
									(*Arbolito).Hijo_derecho  = ( Arbol* ) malloc ( sizeof ( Arbol  ) ) ;
									Sembrar ( (*Arbolito).Hijo_derecho ) ;
								}
							Nuevo_hijo ( (*Arbolito).Hijo_derecho , nodo_bebe ) ;
						}
				}
		}

Nodo* Busca_nodo ( Arbol *Arbolito, char nombre )
	{
		if (  (*((*Arbolito).Raiz)).Nombre == nombre )
			return (*Arbolito).Raiz ;
		else
			{
				if ( nombre <  (*((*Arbolito).Raiz)).Nombre  )  // buscar a la izquierda. No puede estar al lado derecho de la raiz (salvo error de armado)
					{
						if  (  (*Arbolito).Hijo_izquierdo != NULL )
							{
								if ( Busca_nodo (  (*Arbolito).Hijo_izquierdo ,  nombre ) != NULL )
									return Busca_nodo( (*Arbolito).Hijo_izquierdo, nombre ) ;	
							}
						else								// si no hay arbol izquierdo, no existe el elemento buscado
							return NULL ;
					}
				else				//es mayor que la raiz,por lo tanto se busca a la izquierda
					{
						if (  (*Arbolito).Hijo_derecho != NULL )
							{
								if ( Busca_nodo( (*Arbolito).Hijo_derecho , nombre ) != NULL )
									return Busca_nodo( (*Arbolito).Hijo_derecho , nombre ) ;
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}

Nodo* Nodo_padre ( Arbol *Arbolito , Nodo *Adoptado ) 
	{
		if (  (*((*Arbolito).Raiz)).Nombre == (*Adoptado).Nombre )
			return NULL ;
		else
			{
				if ( (*Adoptado).Nombre <  (*((*Arbolito).Raiz)).Nombre  )  // buscar a la izquierda. No puede estar al lado derecho de la raiz (salvo error de armado)
					{
						if  (  (*Arbolito).Hijo_izquierdo != NULL )
							{
								if (  (*((*((*Arbolito).Hijo_izquierdo)).Raiz)).Nombre == (*Adoptado).Nombre )
									return (*Arbolito).Raiz ;
								else
									{
										if ( Nodo_padre (  (*Arbolito).Hijo_izquierdo , Adoptado )  != NULL)
											return Nodo_padre (  (*Arbolito).Hijo_izquierdo , Adoptado ) ;
									}
							}
						else								// si no hay arbol izquierdo, no existe el elemento buscado
							return NULL ;
					}
				else				//es mayor que la raiz,por lo tanto se busca a la izquierda
					{
						if (  (*Arbolito).Hijo_derecho != NULL )
							{
								if (  (*((*((*Arbolito).Hijo_derecho)).Raiz)).Nombre == (*Adoptado).Nombre )
									return (*Arbolito).Raiz ;
								else
									{
										if ( Nodo_padre (  (*Arbolito).Hijo_derecho , Adoptado )  != NULL)
											return Nodo_padre (  (*Arbolito).Hijo_derecho , Adoptado ) ;
									}
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}
	
Nodo* Hijo_izquierdo ( Arbol *Arbolito , Nodo *Padre )
	{
		if (  (*((*Arbolito).Raiz)).Nombre == (*Padre).Nombre )
			if ( (*Arbolito).Hijo_izquierdo != NULL)
				return (*((*Arbolito).Hijo_izquierdo)).Raiz ;
			else
				return NULL ;
		else
			{
				if ( (*Padre).Nombre <  (*((*Arbolito).Raiz)).Nombre  )  // buscar a la izquierda. No puede estar al lado derecho de la raiz (salvo error de armado)
					{
						if  (  (*Arbolito).Hijo_izquierdo != NULL )
							{
								if ( Hijo_izquierdo (  (*Arbolito).Hijo_izquierdo ,  Padre ) != NULL )
									return Hijo_izquierdo( (*Arbolito).Hijo_izquierdo, Padre ) ;
							}
						else								// si no hay arbol izquierdo, no existe el elemento buscado
							return NULL ;
					}
				else				//es mayor que la raiz,por lo tanto se busca a la izquierda
					{
						if (  (*Arbolito).Hijo_derecho != NULL )
							{
								if ( Hijo_izquierdo( (*Arbolito).Hijo_derecho , Padre ) != NULL )
									return Hijo_izquierdo( (*Arbolito).Hijo_derecho , Padre ) ;
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}

Nodo* Hijo_derecho  ( Arbol *Arbolito , Nodo *Padre ) 
	{
		if (  (*((*Arbolito).Raiz)).Nombre == (*Padre).Nombre )
			if ( (*Arbolito).Hijo_derecho != NULL )
				return (*((*Arbolito).Hijo_derecho)).Raiz;
			else
				return  NULL ;
		else
			{
				if ( (*Padre).Nombre <  (*((*Arbolito).Raiz)).Nombre  )  // buscar a la izquierda. No puede estar al lado derecho de la raiz (salvo error de armado)
					{
						if  (  (*Arbolito).Hijo_izquierdo != NULL )
							{
								if ( Hijo_derecho (  (*Arbolito).Hijo_izquierdo ,  Padre ) != NULL )
									return Hijo_derecho( (*Arbolito).Hijo_izquierdo, Padre ) ;
							}
						else								// si no hay arbol izquierdo, no existe el elemento buscado
							return NULL ;
					}
				else				//es mayor que la raiz,por lo tanto se busca a la izquierda
					{
						if (  (*Arbolito).Hijo_derecho != NULL )
							{
								if ( Hijo_derecho( (*Arbolito).Hijo_derecho , Padre) != NULL )
									return Hijo_derecho( (*Arbolito).Hijo_derecho , Padre ) ;
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}

void Leer_nodo ( Arbol *Arbolito , Nodo *un_nodo ) 
	{
		if ( !es_vacio(Arbolito) && un_nodo != NULL )
			{
				printf("\n\nNodo: %c ", (*un_nodo).Nombre );
				if ( Nodo_padre ( Arbolito , un_nodo ) != NULL )
					printf("\n\nPadre: %c ", (*(Nodo_padre ( Arbolito , un_nodo ) )).Nombre );
				else
					printf("Es raiz.\n\nNivel: 1");
				if (  Hijo_izquierdo ( Arbolito , un_nodo) != NULL )	
					printf("\n\nHijo izquierdo: %c ", ( *Hijo_izquierdo(Arbolito,un_nodo ) ).Nombre );
				else
					printf("\n\nNo hay hijo izquierdo");
				if (  Hijo_derecho ( Arbolito , un_nodo) != NULL )	
					printf("\n\nHijo derecho: %c ", ( *Hijo_derecho(Arbolito,un_nodo) ).Nombre );
				else
					printf("\n\nNo hay hijo derecho");
				int i =1 ;
				while  (  Nodo_padre ( Arbolito , un_nodo ) != NULL  )
					{
						un_nodo = Nodo_padre ( Arbolito , un_nodo ) ; 
						i++ ;
					}
				printf("\n\nNivel: %d",i);
			}
		else
			printf("\n\nArbol vacio o nodo inexistente\n\n");
	}
