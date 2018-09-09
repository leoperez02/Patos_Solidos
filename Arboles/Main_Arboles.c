#include  "Arbol.h"

int main ( Lain , to_the_Wired )
	{	
		FILE *cfPtr;
		char archivo[50] ,  cade[54] , nombre ;
		int opcion , n_arboles = -1 , menu = 1 , numero ;
		Arbol *Bambu = ( Arbol* ) malloc (sizeof ( Arbol ) ) ;
		
		while ( menu ) 
			{
				system("cls") ;
				printf("\n\n MENU PRINCIPAL ");
				printf("\n\n\t1. Buscar un nodo en el arbol");
				printf("\n\n\t2. Recorrer arbol en pre-orden");
				printf("\n\n\t3. Recorrer arbol en in-orden");
				printf("\n\n\t4. Recorrer arbol en post-orden");
				printf("\n\n\t5. Cargar arbol desde archivo .txt");				
				printf("\n\n\t6. Eliminar nodo del arbol");				
				printf("\n\n\t7. Eliminar arbol");				
				printf("\n\n\t8. Salir");
				printf("\n\nTeclea el numero de la opcion que quieras: ");
				scanf("%d",&opcion) ;
				fflush(stdin);
			
				switch ( opcion )
					{
						case  1:
							{										
								printf("\n\nTeclea el nombre del nodo a buscar (una letra): ");
								scanf("%c" , &nombre);
								fflush(stdin);
								printf("\n\nRecorrido: ");
								Leer_nodo ( Bambu, Busca_nodo_r (Bambu ,  nombre ) ) ;
								opcion = 0 ;
								printf("\n\n");								
								system( "pause");
								break ;
							}
						case  2:
							{
								printf("\n\nPre-orden: ") ;
								Pre_Orden ( Bambu ) ;
								opcion = 0 ;
								printf("\n\n");
								system( "pause");
								break ;
							}
						case 3:
							{
								printf("\n\nIn-Orden: ");
								In_Orden(Bambu) ;
								opcion = 0 ;	
								printf("\n\n");
								system( "pause");
								break ;
							}
						case 4:
							{
								printf("\n\nPost-Orden: ");
								Post_Orden(Bambu) ;
								opcion = 0 ;	
								printf("\n\n");
								system( "pause");
								break ;
							}
						case 5:
							{
								printf("\n\nEscribe el nombre del archivo: ") ;
								gets(archivo) ;
								fflush(stdin);
								Sembrar ( Bambu ) ;
								if ((cfPtr = fopen(archivo, "r")) == NULL)
									printf("El archivo no se pudo abrir\n");
								else
									{
										while(!feof(cfPtr) )
											{
												fgets( cade, 120,cfPtr) ;
												quita_espacios(cade);
												int Osita ;
												for ( Osita = 0 ; cade[Osita] != '0' ; Osita ++ )
													{
														Nodo *Pandita_Bebe = ( Nodo* ) malloc ( sizeof (Nodo) ) ;
														(*Pandita_Bebe).Nombre = cade[Osita] ;
														Nuevo_hijo ( Bambu , Pandita_Bebe ) ; 
														Bambu = Equilibra ( Bambu, Pandita_Bebe )  ;
													}
												break;
											}
										printf("\nArbol sembrado :)\n\n");
									}
								printf("\n\nAltura: %d\n",mide_arbol(Bambu));
								fclose(cfPtr);
								opcion = 0 ;
								system( "pause");
								break ;
							}
						case 6:
							{
								printf("\n\nTeclea el nombre del nodo a eliminar (una letra): ");
								scanf("%c" , &nombre);
								fflush(stdin);
								Leer_nodo ( Bambu, Busca_nodo (Bambu ,  nombre ) ) ;
								Bambu = Eliminar_nodo ( Bambu , Busca_nodo (Bambu ,  nombre )) ;
								printf("\n\nNodo eliminado\n\n");
								opcion = 0 ;								
								system( "pause");
								break ;
							}
						case 7:
							{
								Talar(Bambu) ;
								opcion = 0 ;
								system( "pause");
								break ;
							}
						case 8:
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