#include "Colas_dinamicas.h"
int main ( Lain, to_the_Wired )
	{	
		Cola *cola1 = ( Cola*) malloc (sizeof (struct Cola));
		Inicializa_cola ( cola1 );
		int opc = 1 ;
		while (opc)
			{
				system("cls");
				printf("\n\nColas dinamicas");
				printf("\n\n0. Salir");
				printf("\n\n1. Agrega un elemento a la cola (push)");
				printf("\n\n2.Elimina un elemento de la cola (pop)");
				printf("\n\nTeclea tu opcion: ");
				scanf("%d",&opc);
				fflush(stdin);
				if (opc == 1 )
					{
						char cara ;
						printf("Teclea el caracter a agregar: ");
						scanf("%c",&cara);
						fflush(stdin);
						push(cola1,cara);
						printf("\n\nLa cola es: ");
						imprime_cola(cola1); 
						system("PAUSE");
					}
				else
					{
						if (opc == 2 )
							{
								printf("\n\nPop: %c",pop(cola1));
								printf("\n\nLa cola es: ");
								imprime_cola(cola1); 
								system("PAUSE");
							}
						else
							printf("\nOpcion incorrecta");
					}
			}
		return to_the_Wired; 
	}