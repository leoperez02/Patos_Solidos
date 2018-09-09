#include "Post_Ordena.h"
#include "../Pila/Pila_Char.h"
#include "validaciones_operadores.h"
void post_ordena( char cadena[50], char post_ordenada[50] ) 
	{
		int i,j ;
		char pila_operadores[50] ;
		pila_operadores[0] = '\0' ;
		post_ordenada  [0] = '\0' ;
		for ( i = 0 ; cadena[ i ] != 0 ; i++ )
			{
				if ( es_letra( cadena[ i ] ) )
					push (post_ordenada,cadena[ i ]) ;
				else
					{
						if ( is_empty ( pila_operadores) )
							push (pila_operadores,cadena[ i ]) ;
						else		
							{
								while ( !is_empty(pila_operadores) )
									{
										if ( es_mayor ( cadena[ i ] , top( pila_operadores ) )  || cadena[ i ] == '('  || top(pila_operadores) == '('  )
											{
												push(pila_operadores,cadena[ i ] ) ;
												break ;
											}
										else
											{		
												if ( cadena[ i ] == ')' )
													{
														while ( top(pila_operadores)  != '('   )
															push(post_ordenada,pop(pila_operadores)) ;	
														cadena[0] = pop ( pila_operadores) ;
														break ;
													}
												else		
													push(post_ordenada,pop(pila_operadores)) ;			
											}
									}
								if ( is_empty(pila_operadores) && cadena[ i ] != ')'  )
									push (pila_operadores,cadena[ i ]) ;
							}
					}
			}
		while ( !is_empty( pila_operadores ) )
			push (post_ordenada,pop(pila_operadores)) ;
	}