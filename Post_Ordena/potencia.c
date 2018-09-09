#include "potencia.h"
int potencia(int base, int exponente)
	{
		int i, resultado = 1;
		if (exponente>=0)
			{
				for ( i = 0 ; i < exponente ; i++)
					{
						resultado = resultado*base ;
					}
			}
		else
			{
				i =( 1/exponente ) * (-1) ;
				resultado = potencia(base,i);
			}
		return resultado;
	}