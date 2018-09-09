#include "Lexico.h"
int lexico(char *p1 , char *p2)
	{
	//	printf("\n\n-->%s",p1);
	//	printf("\n\n-->%s",p2);
		if ( valida_nombre(p1) && valida_nombre(p2) )
			{
			//	printf("\n\nif-->%s",p1);
			//	printf("\n\nif-->%s",p2);
			//	//p1= quita_espacios(p1);
			//	//p2= quita_espacios(p2);
			//	printf("\n\nif2222-->%s",p1);
			//	printf("\n\nif222-->%s",p2);
				int i ; 
				for ( i = 0 ;  i < tam_cad(p1)   &&   i < tam_cad(p2)   ; i++ )
					{
						if ( toascii(p1[ i ]) > toascii(p2[ i ]) )
							{
								//printf("aaaa %d ---> %c y %c " , i ,p1[ i ],p2[ i ] );
								return 1; 
							}
						else
							if (toascii(p1[ i ]) < toascii(p2[ i ]))
								return 2 ;
					}
				if (  tam_cad(p1)  > tam_cad(p2) )
					{
						//printf("\nCadena1 > cadena2");
						return 1;
					}
				else
					{
						if (  tam_cad(p1)  < tam_cad(p2) )
							{
							//	printf("\nCadena1 < cadena2");
								return 2;
							}
						else
							return 0 ;
					}
			}
		else
			{
				printf("\n Las cadenas '%s' y '%s' no son palabras. No se pueden comparar \n",p1,p2);
				return 3 ;
			}
	}