#include "validaciones_operadores.h"
#include "Evalua_Post.h"
#include "../Cadenas/Cadenas.h"
#include "../Pila/Pila_Char.h"
#include "Post_Ordena.h"
#include <stdio.h>
int main (Lain, to_the_Wired)
	{
		char cadena[50] , post_ordenada[50]  , c_valores[50]  , *auxiliar;
		int array_valores[50] = { 1,2,3,4,5,6,7,8,9} , opcion , i, val = 1 ,  menu = 1;
		while ( menu ) 
			{
				system("cls") ;
				printf("\n\n MENU PRINCIPAL");
				printf("\n\n\t1. Validacion para una expresion en infijo");
				printf("\n\n\t2. Conversion de una expresion en infijo a post-fijo");
				printf("\n\n\t3. Evaluacion de una cadena en post-fijo (ingresar valores)");
				printf("\n\n\t4. Conversion de infija a post-fija y evaluacion");
				printf("\n\n\t5. Salir ");
				printf("\n\nTeclea el numero de la opcion que quieras: ");
				scanf("%d",&opcion) ;
				fflush(stdin);
				switch ( opcion )
					{
						case  1:
							{		
								printf("\n\nEscribe la expresion en notacion infija: ") ;
								gets(cadena) ;
								fflush(stdin);
								quita_espacios(cadena);
								printf("cadena %s ", cadena);
								if ( es_expresion_valida(cadena) )	
									printf( "\nExpresion valida\n\n") ;
								else
									printf( "\n\nExpresion invalida\n\n") ;
								opcion = 0 ;	
								system( "pause");
								break ;
							}
						case  2:
							{
								while(opcion)
									{
										printf("\n\nEscribe la expresion en notacion infija: ") ;
										gets(cadena) ;
										fflush(stdin);
										quita_espacios(cadena);
										if ( es_expresion_valida(cadena) )	
											{
												post_ordena( cadena, post_ordenada)  ;
												printf("\n\n\nCadena post ordenada: %s \n\n" ,post_ordenada);
												opcion = 0 ;
											}
										else
											printf( "\n\nExpresion invalida\n\n") ;
									}
								system( "pause");
								break ;
							}
						case  3:	
							{
								while (val) 
									{
										printf("\n\nIngresa los valores de las literales de este modo : A,B,C,D,E,.... \nEjemplo:\n\n Valores: 2,4,2,6,7,5,10 \n Valores: ");
										gets(c_valores);
										fflush(stdin);
										quita_espacios(c_valores);
										val = 0 ;
										for ( i = 0 , auxiliar = strtok(c_valores,",")  ; auxiliar != NULL ; auxiliar = strtok(NULL, ",") , i++)
											array_valores[i] = atoi(auxiliar) ; 
									}
								val = 1 ;
								printf("\n\nEscribe la expresion en notacion post-fija: ") ;
								gets(post_ordenada) ;
								fflush(stdin);
								quita_espacios(post_ordenada);
								printf("\n\n Resultado = %d \n\n" , evalua_post(post_ordenada,array_valores) );
								opcion = 0 ;
								system( "pause");
								break ;
							}
						case  4:
							{
								while(opcion)
									{
										printf("\n\nEscribe la expresion en notacion infija: ") ;
										gets(cadena) ;
										fflush(stdin);
										quita_espacios(cadena);
										if ( es_expresion_valida(cadena) )	
											{
												post_ordena(cadena , post_ordenada)  ;
												printf("\n\nCadena post ordenada: %s  " ,post_ordenada);
												printf("\n\nResultado = %d \n\n" ,evalua_post(post_ordenada,array_valores))  ;
												opcion = 0 ;
											}
										else
											printf( "\n\nExpresion invalida\n\n") ;
									}
								system( "pause");
								break ;
							}
						case 5:
							{
								system("cls") ;
								menu = 0 ;
								break ;
							}
						default :
							{
								menu = 1;
								opcion = 0;
								break ;
							}
					}
			}	
		return to_the_Wired ;
	}