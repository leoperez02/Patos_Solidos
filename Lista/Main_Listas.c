#include "Listas.h"
int main ( Lain, to_the_Wired)
	{
		int opc = 1 ;
		char *nombre = (char*) malloc (sizeof(char)*50);
		char *archivo = (char*) malloc (sizeof(char)*50);
		Lista *La_lista  = (Lista*) malloc ( sizeof (Lista )) ;
		Nodo *El_nodo = (Nodo*) malloc (sizeof (Nodo)) ;
		crea_lista (La_lista) ;
		while (opc)
			{
				system("cls") ; 
				printf("\n\n\tMENU PRINCIPAL - Listas \n\n");
				printf("\n1. Cargar lista desde archivo .txt\n");
				printf("\n2. Agregar registro desde teclado\n");
				printf("\n3. Buscar registro\n");
				printf("\n4. Eliminar registro\n");
				printf("\n5. Imprimir lista\n");
				printf("\n6. Salir\n");
				printf("\nTeclea la opcion deseada: ");
				scanf("%d",&opc);
				fflush(stdin);
				switch (opc)
					{
						case 1:
							printf("\nArchivo: ");
							scanf("%s" , archivo ) ;
							fflush(stdin);
							cargar_lista ( La_lista , archivo); 
							printf("\nTarea Finalizada\n\n");
							system("Pause");
						break;
						case 2:
							printf("\nCaptura los datos del registro ...\n\n");
							Nodo *Oso = (Nodo*) malloc (sizeof (Nodo)) ;
							crea_nodo (Oso) ;
							agrega (La_lista,Oso) ;
							printf("\nEl registro se agrego correctamente\n\n");
							system("Pause");
						break;
						case 3:
							printf("\nNombre: ");
							scanf("%s" , nombre ) ;
							fflush(stdin);
							El_nodo = busca (La_lista,nombre) ;
							if (El_nodo != NULL)
								printf("\n\nResultado: %s\t%s\t%s\t%d\n", (*El_nodo).nombre,	(*El_nodo).tel, (*El_nodo).correo , (*El_nodo).edad) ;
							else
								printf("\nEl registro con nombre '%s' no se encontro.\n\n", nombre);
							system("Pause");
						break;
						case 4:
							printf("\nNombre: ");
							scanf("%s" , nombre ) ;
							fflush(stdin);
							El_nodo = busca (La_lista,nombre) ;
							if (El_nodo != NULL)
								{
									printf("\n\nResultado: %s\t%s\t%s\t%d\n", (*El_nodo).nombre,	(*El_nodo).tel, (*El_nodo).correo , (*El_nodo).edad) ;
									elimina (La_lista,nombre);
									printf("\n\nResgistro eliminado\n\n");
								}
							else
								printf("\nEl registro con nombre '%s' no se encontro.\n\n", nombre);
							system("Pause");
						break;
						case 5:
							if (es_vacia(La_lista))
								printf("\n\nLista vacia");
							else
								imprime_lista(La_lista) ;
							printf("\n");
							system("Pause");
						break;
						case 6:	opc = 0 ;	break;
						default:	break;
					}
			}
		return to_the_Wired ;
	}