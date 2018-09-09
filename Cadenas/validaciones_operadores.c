#include "validaciones_operadores.h "
#include "Cadenas.h"
int es_letra(char caracter)
	{
		if (  (toascii ( caracter ) < 65    ||   toascii ( caracter ) > 90 )   && ( toascii ( caracter ) < 97 || toascii (caracter ) > 122  ))  //no es letra mayuscula ni minuscula
			return 0 ; 
		else
			return 1 ;
	}
int es_operador(char operador)
	{
		if ( operador != '+' && operador != '-' && operador != '*' && operador != '/'  && operador!='^' ) 
			return 0;
		else
			return 1 ;
	}
int es_mayor(char c1 ,char c2)
	{	
		if ( c1 == '^' )
			{
				if (c2 == '^' )
					return 0 ;
				else
					return 1 ;
			}
		else
			{
				if ( c1 == '/' || c1== '*' )
					{
						if ( c2 == '/' || c2 == '*' )
							return 0 ;
						else
							return  1 ;
					}
				else
					return 0 ; 
			}
	}
int es_igual(char c1, char c2)
	{
		if ( c1 == '^' )
			{
				if (c2 == '^' )
					return 1 ;
				else
					return 0 ;
			}
		else
			{
				if ( c1 == '/' || c1== '*' )
					{
						if ( c2 == '/' || c2 == '*' )
							return 1 ;
						else
							return  0 ;
					}
				else
					{
						if ( c2 == '+' || c2 == '-' )
							return 1 ;
						else
							return  0 ;
					}
			}
	}
int es_expresion_valida ( char cadena[] ) 
	{	
		int i ,bandera_letra,bandera_operador, bandera_parentesis , validador = 1 , longitud  ;
		char caracter ;
		
		longitud = tam_cad(cadena) ;
		
		if ( longitud  < 3 )    // restriccion de tamaño
			return 0 ;
		else						 // restricciones ...
			{
				//BUSCAR PARENTESIS EN LA CADENA
				bandera_parentesis = 0 ;
				for ( i = 0 ; i < longitud ; i++)
					if ( cadena[i] == '('  || cadena[i] == ')' )
							bandera_parentesis = 1 ;
				// SI LA EXPRESION TIENE PARENTESIS, ENVIAR AL MÉTODO  VALIDADOR DE PARÉNTESIS
				if (bandera_parentesis == 1 )
					validador = valida_parentesis(cadena);
				else
					{
						if (validador == 0 )	
							return 0 ;
						else
							{	
								caracter = *(cadena+0) ;  //inicial
								if (  !(es_letra(caracter)) )  
									return 0 ;
								else
									{
										caracter = *( cadena + longitud -1 ) ;  //final
										if ( !(es_letra( caracter))  )
												return 0 ;
										else
											{
												for ( i = 0 , bandera_letra = 0 , bandera_operador = 0 ; i < longitud ; i++ )
													{
														caracter = *(cadena+i) ;
														if ( !(es_letra(caracter))   &&   !( es_operador(caracter))  ) 
																return 0;
														else
															{
																if ( es_letra(caracter) )
																	{
																		bandera_letra ++ ;
																		if ( bandera_letra >= 2 )
																			return 0 ; 
																		else
																			bandera_operador = 0 ;
																	}
																else
																	{
																		bandera_operador ++ ;
																		if ( bandera_operador >= 2 )
																				return 0 ; 
																		else
																				bandera_letra = 0 ;
																	}
															}
													}
											}
									}
							}	
					}
				return validador ;	
			}
	}
int valida_parentesis( char cadena_ori[] )  
	{
		int i, j, contador, contador2, index1, longitud_cadena, num_p_a = 0 , num_p_c = 0 , validador = 1 ; 
		char c_auxiliar[50] ,  cadena[50];
		
		longitud_cadena= tam_cad(cadena_ori) ;
		//copiar cadena origiinal a cadena para manipulacion ...
		for ( i = 0 ; i < longitud_cadena ; i++) 
			cadena[i] = cadena_ori[i] ;
		cadena[longitud_cadena] = '\0' ;
		//VALIDACION PARA IGUAL NUMERO DE PARENTESIS DE CIERRE QUE DE APERTURA
		for ( i = 0 ; i < longitud_cadena ; i++ )
			{
				if ( cadena[i] == '(' )
					num_p_a ++ ;
				else
					{
						if (cadena[i] == ')' )
							num_p_c ++ ;
					}
			}
			//COMPARANDO numero de  APRERTURA  CON CIERRE
		if ( num_p_a != num_p_c )
			return 0 ;
		else
			{
				if ( cadena[0] == ')' )
					return 0 ;
				else
					{
						if (cadena[ (longitud_cadena-1)]  == '(' )
							return 0 ;
						else
							{
								for ( i = 0 ; i < longitud_cadena ; i++ )
									{
										if (cadena[i] == '(' )
											{
												if( i == 0 )
													{
														if ( es_operador( cadena[i+1] ))
															return 0 ;
													}
												else
													{
														if ( es_operador( cadena[i+1] ) || es_letra( cadena[i-1]))
															return 0 ;		
													}
											}
										else
											{
												if ( cadena[i] == ')' )
													{
														if (i == (longitud_cadena-1))
															{
																if (es_operador(cadena[i-1]))
																	return 0 ;
															}
														else
															{
																if (es_operador(cadena[i-1]) || es_letra(cadena[i+1]))
																	return 0 ;		
															}
													}
											}
									}
							}
					}
			}
		//Verificar que la expresión dentro de cada paréntesis sea válida
		//1. Recorrer la cadena hasta hallar el primer paréntesis de cierre
		//2. Recorrer la cadena en orden inverso a partir del índice anterior hasta primer parentesis de apertura
		//3. Guardar la expresión (cadena) en cadena_auxiliar y enviar al método de es_expresion_valida() 
			//3.1 Si el método regresa cero --> terminar el método (return 0)
			//3.2 Si regresa uno --> continuar con el recorrido de la cadena principal 
		////printf("\n\n Cadena original = %s",cadena);	
		for ( i = 0 ; i < longitud_cadena ; i++ )
			{
				if ( cadena[i] == ')' )
					{
						//printf("\n\nParentesis de cierre ')' hallado en indice: %d",i);			
						for ( j = 1 , contador = 0 , contador2 = 0 ; j <= i ; j++ , contador++ )
							{
								if ( cadena[ i - j ] != '(' )
									{
										c_auxiliar[contador] = cadena[ i - j ] ;
										contador2++ ;
									}
								else
									{
										index1 = i - j ;
										break ;
									}
							}
						c_auxiliar[contador2] =  '\0' ;	
						//printf("\n\nSub-cadena = %s", c_auxiliar);
						validador = es_expresion_valida(c_auxiliar) ;
						if ( validador == 0 )
							return 0 ;
						else
							{
								//printf("Es valida la sub cadena %s ",c_auxiliar);
								cadena[index1] = 'H' ;
								for ( j = index1+1 , contador = 1; cadena[j] != '\0'    ; j++ , contador++)
									cadena[j] = cadena[i+contador] ;
								//printf( "\nCadena actualizada: %s ",cadena);
								longitud_cadena = tam_cad(cadena_ori); 
							}
					}
			}
		longitud_cadena = tam_cad(cadena_ori) ; 
		//printf("validador = %d",validador);
		if (longitud_cadena > 3 )
			validador = es_expresion_valida(cadena);
		else
			validador = 1 ;
		//printf("validador = %d",validador);
		return validador ;
	}