#include "validaciones_operadores.h"
#include "../Cadenas/Cadenas.h"
#include "Evalua_Post.h"
#include "potencia.h"
int evalua_post( char post_ordenada[] , int array_valores[]) 
	{
		int  valor1, valor2, contador, i, resultado = 0 , lon_cadena = 0  , j , cont ;
		char cara1, cara2, cara_nueva ;
		
		lon_cadena = tam_cad( post_ordenada) ;
		
		//printf( "\nInicia funcion de evaluacion... ");
		while ( lon_cadena > 1)	
			{
				//printf( "\n Entra al while");
				//1. Busca primer operador e identifica la posicion en el arreglo (i) 
				for ( i = 0 , contador = 0  ; i < lon_cadena ; i++ )    	
					{
						//printf( "\n Entra al for %d", i );

						if ( es_operador(post_ordenada[i]) ) // Posición: i
							{
								//printf("\nLongi cadena: %d",lon_cadena);	
								//printf( "\nOperador %c ",post_ordenada[i]) ;
								
								//2. Obtiene los dos caracteres anteriores y busca su valor numérico
								cara1 = post_ordenada[i-2] ;   //printf("\n\nCaracter1= %c",cara1);
								cara2 = post_ordenada[i-1] ;   //printf("\n\nCaracter2= %c",cara2);
								
									// A corresponde al primer valor del arreglo --> A = array_valores[0] 
										// En código ascii sería A = 65 , entonces ... 
										// 65 - (65) = 0 ----> corresponde A al ídice 0 en el array_valores[] ;
										// toascii( A ) - 65 = i ----> valor1 = array_valores[toascii(A)-65] ;
									
										// valor1 = array_valores[ toascii(caracter1) - 65 ] ;
										
										//Nota: Se require convertir a mayúsculas ....
										if ( toascii(cara1) < 65 || toascii(cara1) > 90)
											cara1 = (char)( toascii(cara1) - 32 ) ;	
										if ( toascii(cara2) < 65 || toascii(cara2) > 90)
											cara2 = (char)( toascii(cara2) - 32 ) ;
										//------------

								//printf("toascii %d", toascii(cara1));
								valor1 = array_valores[toascii(cara1) - 65 ] ;
								valor2 = array_valores[toascii(cara2) - 65 ] ;
									
								//printf( "\n Valor 1: %d", valor1);
								//printf( "\n valor 2: %d", valor2);

								//3. Realiza la operación indicada y guarda una literal nueva con el valor obtenido
								if (post_ordenada[i] == '+')
									{resultado = valor1 + valor2 ; }
								if (post_ordenada[i] == '-')
									{resultado = valor1 - valor2 ;  }
								if (post_ordenada[i] == '*')
									{resultado = valor1 * valor2 ; }
								if (post_ordenada[i] == '/')
									{
										if ( valor2 != 0 )
											resultado = valor1 / valor2 ;
										else
											{
												//printf( "\n\nERROR. Division por cero\n\n");
												return 0 ;
											}
									}
								if (post_ordenada[i] == '^' )
									{resultado = potencia(valor1, valor2) ; }
			 
								//printf( "\n Resultado = %d" , resultado);
								cara_nueva = (char)( 72 + contador ) ; 
								array_valores[7+contador] = resultado ;
								contador++ ;
						
								//4. Inserta en la cadena original la nueva literal y recorre dos posiciones el resto
								post_ordenada[i-2] = cara_nueva;
							
								for ( j = i-1 ,cont = 1; j < lon_cadena-2 ; j++ , cont++)
									{
										post_ordenada[j]  = post_ordenada[i+cont] ;
									}
								//printf( "\nCadena actualizada: %s ",post_ordenada);
				
								//Actualizar longitud de cadena y reiniciar posicion de búsqueda
								lon_cadena = lon_cadena - 2;											
								i = -1;
							}
					}
			}//5. Mientras la longitud de la cadena sea mayor a 1 Vuelve al paso 1
		//6. Si la longitud de la cadena es 1, busca el valor de la literal y devuelve su valor terminando el proceso.
	
		if (lon_cadena == 1)
			{
				cara1 = post_ordenada[0] ;
				resultado = array_valores[toascii(cara1) - 65 ] ;
			}
		return resultado ;
	}