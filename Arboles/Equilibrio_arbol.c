#include "Arbol.h"

//  Funciones de equilibrio ...
	
int mide_arbol ( Arbol *Arbolito ) 
	{
		if (  Arbolito !=NULL && !es_vacio(Arbolito))
			{
				int altura_iz = 1;
				int altura_der = 1;
				
				if (   (*Arbolito).Hijo_izquierdo != NULL )
					altura_iz = altura_iz + mide_arbol ((*Arbolito).Hijo_izquierdo) ;
				else
					altura_iz = 0 ;
				if (  (*Arbolito).Hijo_derecho != NULL )
					altura_der = altura_der + mide_arbol ((*Arbolito).Hijo_derecho) ; 
				else
					altura_der = 0 ;
				
				if ( altura_der == 0 && altura_iz== 0  )
					return 1 ;
				else
					{
						if ( altura_iz >= altura_der)
							return altura_iz ;
						else
							return altura_der ;
					}
			}
		else
			return 0 ;
	}

int Calcula_indice( Arbol* Arbolito )
	{
		(*((*Arbolito).Raiz)).Indice = mide_arbol( (*Arbolito).Hijo_derecho ) - mide_arbol( (*Arbolito).Hijo_izquierdo ) ;
		return (*((*Arbolito).Raiz)).Indice ;
	}

Arbol* Equilibra (Arbol* Bambu , Nodo *Pandita_bebe )
	{
		if ( !es_vacio(Bambu) )
			{
				Arbol *Arbolito = ( Arbol* ) malloc ( sizeof( Arbol ) ) ;
				Nodo *nodo_bebe = ( Nodo* ) malloc ( sizeof ( Nodo) ) ;
				nodo_bebe = Pandita_bebe ;
				while ( Padre_de (Bambu , nodo_bebe) != NULL )
					{
						Arbolito = Padre_de (Bambu, nodo_bebe) ;
						
						if( Calcula_indice(Arbolito) == 2  )
							{												//desequilibrio derecho
								if ( Calcula_indice((*Arbolito).Hijo_derecho) > 0)
									{
										printf("\n des derecho. Rotacion simple");
										system("pause");
										
										if ( Padre_de ( Bambu , (*Arbolito).Raiz ) == NULL )
											Bambu = Rotacion_I (Arbolito,'+') ; // '+' parametro para rotar a la derecha
										else
											{
												if  (  (*Arbolito).Raiz  ==  Hijo_izquierdo( Bambu, Nodo_padre( Bambu ,((*Arbolito).Raiz)) ) )
													(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_izquierdo = Rotacion_I (Arbolito,'+') ;
												else
													(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_derecho = Rotacion_I (Arbolito,'+') ;
											}								
									}
								else
									{
										printf("\n des derecho. Rotacion doble");
										system("pause");
										if ( Padre_de ( Bambu , (*Arbolito).Raiz ) == NULL )
											Bambu = Rotacion_II (Arbolito,'+') ; // '+' parametro para rotar a la derecha
										else
											{
												if  (  (*Arbolito).Raiz  ==  Hijo_izquierdo( Bambu, Nodo_padre( Bambu ,((*Arbolito).Raiz)) ))
													(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_izquierdo = Rotacion_II (Arbolito,'+') ;
												else
													(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_derecho = Rotacion_II (Arbolito,'+') ;
											}			
									}
							}
						else
							{
								if ( Calcula_indice(Arbolito) == -2 )
									{												//desequilibrio izquierdo
										if ( Calcula_indice((*Arbolito).Hijo_izquierdo) < 0)
											{
												printf("\n des izquierdo. Rotacion simple");
												system("pause");
												if ( Padre_de ( Bambu , (*Arbolito).Raiz ) == NULL )
													Bambu = Rotacion_I (Arbolito,'-') ; // '-' parametro para rotar a la izquierda
												else
													{
														if  (  (*Arbolito).Raiz  ==  Hijo_izquierdo( Bambu, Nodo_padre( Bambu ,((*Arbolito).Raiz))) )
															(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_izquierdo = Rotacion_I (Arbolito,'-') ;
														else
															(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_derecho = Rotacion_I (Arbolito,'-') ;
													}			
											}
										else
											{
												printf("\n des izquierdo. Rotacion doble");
												system("pause");
												if ( Padre_de ( Bambu , (*Arbolito).Raiz ) == NULL )
													Bambu = Rotacion_II (Arbolito,'-') ; // '-' parametro para rotar a la izquierda
												else
													{
														if  (  (*Arbolito).Raiz  ==  Hijo_izquierdo( Bambu, Nodo_padre( Bambu ,((*Arbolito).Raiz)) ))
															(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_izquierdo = Rotacion_II (Arbolito,'-') ;
														else
															(*Padre_de ( Bambu , (*Arbolito).Raiz ) ).Hijo_derecho = Rotacion_II (Arbolito,'-') ;
													}			
											}
									}
							}
						nodo_bebe = (*Arbolito).Raiz ;
					}
			}
		return Bambu ;
	}
	
Arbol* Rotacion_I (Arbol *Arbolito , char sentido)
	{
		Arbol *raiz_bambu = (Arbol*) malloc ( sizeof ( Arbol ));
		Arbol *rama_bambu = (Arbol*) malloc ( sizeof ( Arbol ));
		if ( sentido == '+' )			// Desequilibrio a la derecha, rotacion derecha
			{
				raiz_bambu = Arbolito ;
				rama_bambu = (*raiz_bambu).Hijo_derecho ;
				(*raiz_bambu).Hijo_derecho  = (*rama_bambu).Hijo_izquierdo ;
				(*rama_bambu).Hijo_izquierdo = raiz_bambu ;
				Arbolito = rama_bambu ;
			}
		else								// Desequilibrio a la izquierda, rotacion izquierda
			{
				raiz_bambu = Arbolito ;
				rama_bambu = (*raiz_bambu).Hijo_izquierdo ;
				(*raiz_bambu).Hijo_izquierdo  = (*rama_bambu).Hijo_derecho ;
				(*rama_bambu).Hijo_derecho = raiz_bambu ;
				Arbolito = rama_bambu ;
			}
		return Arbolito ;
	}

Arbol* Rotacion_II (Arbol *Arbolito , char sentido)
	{
		Arbol *raiz_bambu = (Arbol*) malloc ( sizeof ( Arbol ));
		Arbol *rama_bambu = (Arbol*) malloc ( sizeof ( Arbol ));
		Arbol *panda_bambu = (Arbol*) malloc ( sizeof ( Arbol ));
		if ( sentido == '+' )			// Desequilibrio a la derecha, rotacion derecha
			{
				raiz_bambu = Arbolito ;
				rama_bambu = (*raiz_bambu).Hijo_derecho ;
				panda_bambu = (*rama_bambu).Hijo_izquierdo ;
				(*rama_bambu).Hijo_izquierdo = (*panda_bambu).Hijo_derecho;
				(*panda_bambu).Hijo_derecho = rama_bambu ;
				(*raiz_bambu).Hijo_derecho = panda_bambu ;
				Arbolito = raiz_bambu ;
			}
		else								// Desequilibrio a la izquierda, rotacion izquierda
			{
				raiz_bambu = Arbolito ;
				rama_bambu = (*raiz_bambu).Hijo_izquierdo ;
				panda_bambu = (*rama_bambu).Hijo_derecho ;
				(*rama_bambu).Hijo_derecho = (*panda_bambu).Hijo_izquierdo;
				(*panda_bambu).Hijo_izquierdo = rama_bambu ;
				(*raiz_bambu).Hijo_izquierdo = panda_bambu ;
				Arbolito = raiz_bambu ;
			}
		return Rotacion_I(Arbolito,sentido) ;
	}

Arbol* Eliminar_nodo ( Arbol *Arbolito  , Nodo  *un_nodo) 	
	{
		if (Busca_nodo(Arbolito,(*un_nodo).Nombre) != NULL )
			{
				if ( mide_arbol(Arbolito) == 1)
					{
						Sembrar(Arbolito);
						return Arbolito;
					}
				else
					{
						printf("\nEliminando...");
						//Caso I. Nodo hoja
						if ( Hijo_izquierdo(Arbolito,un_nodo) == NULL  && Hijo_derecho(Arbolito,un_nodo) == NULL )
							{
								printf("\nEntrando en caso I");
								Arbol *Bambu = Padre_de ( Arbolito , un_nodo) ;
								if ( (*Bambu).Hijo_derecho != NULL)
									{
										if ( (*((*Bambu).Hijo_derecho)).Raiz == un_nodo)
											{
												printf("\nBorrando derecho");
												(*Bambu).Hijo_derecho = NULL ;
											}
									}
								if ((*Bambu).Hijo_izquierdo != NULL)
									{
										if ( (*((*Bambu).Hijo_izquierdo)).Raiz == un_nodo)
											{
												printf("\nBorrando izquierdo");
												(*Bambu).Hijo_izquierdo = NULL ;
											}
									}
								return Arbolito ;
							}
						else
							{
								if ( (Hijo_izquierdo(Arbolito,un_nodo) != NULL  && Hijo_derecho(Arbolito,un_nodo) == NULL) || (Hijo_izquierdo(Arbolito,un_nodo) == NULL  && Hijo_derecho(Arbolito,un_nodo) != NULL)) // Si tiene un solo hijo, este toma su lugar ...
									{
										printf("\nEntrando en caso II");
										Arbol *Bambu = Padre_de ( Arbolito , un_nodo) ;
										if ( Bambu == NULL ) // Borrar raiz con un solo hijo
											{
												printf("\nborrando raiz");
												Bambu = Arbolito ;
												if ( Hijo_izquierdo(Arbolito,un_nodo) !=NULL )
													{
														printf("\nizqu: ");
														Bambu = (*Arbolito).Hijo_izquierdo;
													}
												else
													{
														printf("\ndere");
														Bambu = (*Bambu).Hijo_derecho;
													}
												return Bambu ;
											}
										else
											{
												if ( Hijo_izquierdo(Arbolito,un_nodo) != NULL)
													{
														if ( un_nodo == Hijo_izquierdo(Arbolito,Ver_Raiz(Bambu)))
															(*Bambu).Hijo_izquierdo = (*((*Bambu).Hijo_izquierdo)).Hijo_izquierdo ;
														else
															(*Bambu).Hijo_derecho = (*((*Bambu).Hijo_derecho)).Hijo_izquierdo ;
													}
												else
													{
														if ( un_nodo == Hijo_izquierdo(Arbolito,Ver_Raiz(Bambu)))
															(*Bambu).Hijo_izquierdo = (*((*Bambu).Hijo_izquierdo)).Hijo_derecho ;
														else
															(*Bambu).Hijo_derecho = (*((*Bambu).Hijo_derecho)).Hijo_derecho ;
													}
												return Arbolito ;
											}
									}
								else		// Tiene dos hijos ... sube el derecho
									{
										printf("\nEntrando en caso III");
										
										if ( mide_arbol(Arbolito) == 2)
											{
												printf("\nArbol de altura 2: sube hijo derecho");
												if ( (*Arbolito).Hijo_derecho != NULL )
													{
														(*((*Arbolito).Hijo_derecho)).Hijo_izquierdo = (*Arbolito).Hijo_izquierdo ;
														return (*Arbolito).Hijo_derecho ;
													}
											}
										else
											{
												printf("\nEmpezando algoritmo de eliminacion recursiva...");
												
												// Caso de eliminacion de raiz ... 
												if ( un_nodo == Ver_Raiz(Arbolito))
													{
														Arbol *aux = Eliminar_nodo( (*Arbolito).Hijo_derecho , Ver_Raiz((*Arbolito).Hijo_derecho)) ;
														Arbol *izquierdo = (*Arbolito).Hijo_izquierdo ;
														Arbol *Final = (*Arbolito).Hijo_derecho;
														(*Final).Hijo_derecho = aux; 
					                                    (*Final).Hijo_izquierdo = izquierdo ; 
														return Final;
													}	// Fin ...
												else
													{
														// Se obtiene padre del nodo a eliminar, se envia a la funcion el nodo a eliminar como nuevo arbol y el resultado se asigna como nuevo hijo de dicho padre, ya sea izquierdo o derecho
														Arbol *Padre = Padre_de ( Arbolito , un_nodo) ;
														if ( un_nodo == Ver_Raiz( (*Padre).Hijo_izquierdo))
															(*Padre).Hijo_izquierdo  = Eliminar_nodo ( (*Padre).Hijo_izquierdo , Ver_Raiz((*Padre).Hijo_izquierdo));
														else
															(*Padre).Hijo_derecho  = Eliminar_nodo ( (*Padre).Hijo_derecho , Ver_Raiz((*Padre).Hijo_derecho));
														return Arbolito ;
													}
											}
									}
							}
					}
			}
		else
			return Arbolito;
	}

Arbol* Padre_de ( Arbol *Arbolito , Nodo *Adoptado) 		//--> Algoritmo de método Nodo_Padre() , pero que regresa arbol
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
									return Arbolito ;
								else
									{
										if ( Padre_de (  (*Arbolito).Hijo_izquierdo , Adoptado )  != NULL)
											return Padre_de (  (*Arbolito).Hijo_izquierdo , Adoptado ) ;
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
									return Arbolito ;
								else
									{
										if ( Padre_de (  (*Arbolito).Hijo_derecho , Adoptado )  != NULL)
											return Padre_de (  (*Arbolito).Hijo_derecho , Adoptado ) ;
									}
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}

Nodo* Busca_nodo_r ( Arbol *Arbolito, char nombre )
	{
		if (  (*((*Arbolito).Raiz)).Nombre == nombre )
			{
				printf("%c",  (*(*Arbolito).Raiz).Nombre);
				return (*Arbolito).Raiz ;
			}
		else
			{
				printf("%c --> ",  (*(*Arbolito).Raiz).Nombre);
				if ( nombre <  (*((*Arbolito).Raiz)).Nombre  )  // buscar a la izquierda. No puede estar al lado derecho de la raiz (salvo error de armado)
					{
						if  (  (*Arbolito).Hijo_izquierdo != NULL )
							{
								
								if ( Busca_nodo_r (  (*Arbolito).Hijo_izquierdo ,  nombre ) != NULL )
									{
										printf("%c --> ",  (*Ver_Raiz((*Arbolito).Hijo_izquierdo)).Nombre);
										return Busca_nodo( (*Arbolito).Hijo_izquierdo, nombre ) ;	
									}
							}
						else								// si no hay arbol izquierdo, no existe el elemento buscado
							return NULL ;
					}
				else				//es mayor que la raiz,por lo tanto se busca a la izquierda
					{
						if (  (*Arbolito).Hijo_derecho != NULL )
							{
								
								if ( Busca_nodo_r( (*Arbolito).Hijo_derecho , nombre ) != NULL )
									{
										printf("%c --> ",  (*Ver_Raiz((*Arbolito).Hijo_derecho)).Nombre);
										return Busca_nodo( (*Arbolito).Hijo_derecho , nombre ) ;
									}
							}
						else								// si no hay arbol DERECHO, no existe el elemento buscado
							return NULL ;
					}
			}
	}