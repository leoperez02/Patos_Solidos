#include "Listas.h"

int es_vacia ( Lista *una_lista ) 
	{
		return !(*una_lista).longitud ; 
	}
	
void imprime_lista ( Lista *una_lista ) 
	{	
		int i ; 
		(*una_lista).Buscador = (*una_lista).Inicial ;
		for ( i = 0 ; i < (*una_lista).longitud ; i++ )
			{
				printf("\n%d %s", (i+1), (*(*una_lista).Buscador).nombre) ;
				printf("\t%s" ,				   (*(*una_lista).Buscador).tel);
				printf("\t%s" , 			   (*(*una_lista).Buscador).correo);
				printf("\t%d \n" ,			   (*(*una_lista).Buscador).edad) ;
				(*una_lista).Buscador =(*(*una_lista).Buscador).Siguiente ;
			}
	}

void crea_lista ( Lista *una_lista ) 
	{
		(*una_lista).Inicial = (Nodo*) malloc (sizeof (Nodo)) ;
		(*una_lista).Final = (Nodo*) malloc (sizeof (Nodo)) ;
		(*una_lista).Buscador = (Nodo*) malloc (sizeof (Nodo)) ;		
		(*una_lista).Buscador = NULL ;
		(*una_lista).longitud = 0 ;
	}

void crea_nodo (Nodo *un_nodo )
	{
		(*un_nodo).nombre  = (char*) malloc (sizeof (char ) * 20) ;
		(*un_nodo).tel  = (char*) malloc (sizeof (char ) * 20) ;
		(*un_nodo).correo  = (char*) malloc (sizeof (char ) * 20) ;
		(*un_nodo).Anterior  = (Nodo*) malloc (sizeof (Nodo)) ;
		(*un_nodo).Siguiente= (Nodo*) malloc (sizeof (Nodo)) ;
		(*un_nodo).Anterior   = NULL ;
		(*un_nodo).Siguiente = NULL ;
		printf("\nEscribe el nombre: ");	
		scanf( "%s" , (*un_nodo).nombre);			fflush(stdin) ;
		printf("\nEscribe el telefono: ");
		scanf( "%s" ,(*un_nodo).tel   ); 				fflush(stdin) ;
		printf("\nEscribe el correo: ");		
		scanf( "%s" ,(*un_nodo).correo   );			fflush(stdin) ;
		printf("\nEscribe la edad: ");
		scanf ( "%d" , &((*un_nodo).edad));		fflush(stdin) ;
	}

int son_iguales (Nodo *n1 , Nodo *n2)
	{	
		if ( (*n1).nombre != (*n2).nombre )
			return 0 ;
		else
			{
				if ( (*n1).tel != (*n2).tel )
					return 0 ;
				else
					{
						if ( (*n1).correo != (*n2).correo )
							return 0 ;
						else
							{
								if ( (*n1).edad != (*n2).edad )
									return 0 ;
								else
									return 1 ;
							}
					}
			}
	}

Nodo* busca ( Lista *una_lista , char *nombre ) 
	{
		int i ; 
		if (  (*una_lista).Buscador == NULL) // Busca desde el principio 
			{
				(*una_lista).Buscador = (*una_lista).Inicial ;
				for ( i = 0 ; i < (*una_lista).longitud ; i++ )
					{		printf("       ");
						if ( lexico (  (*( (*una_lista).Buscador )).nombre , nombre ) == 0 ) 
							return (*una_lista).Buscador  ;
						else
							(*una_lista).Buscador =(*(*una_lista).Buscador).Siguiente ;
					}
				return NULL ;  // No se encontró el nodo
			}
		else //Empieza a buscar desde la referencia que tenga el Buscador 
			{ printf("       ");
				i = lexico(nombre ,(*( (*una_lista).Buscador)).nombre) ;
				if (i == 0)  														// Si el nombre es el nombre que tiene el buscador, regresa el buscador :D
					return (*una_lista).Buscador ;
				else
					{
						if ( i == 3)
							return NULL ; //Termino incorrecto de busqueda o registro mal capturado
						else
							{
								while ( (*una_lista).Buscador != NULL )
									{
										if ( ((*( (*una_lista).Buscador )).nombre , nombre )==0) 
											return (*una_lista).Buscador  ;
										else
											{
												if ( i == 1 ) // Si el nombre está alfabeticamente después, busca a la derecha 
													(*una_lista).Buscador =(*(*una_lista).Buscador).Siguiente ;
												else //sino, busca a la izquierda 
													(*una_lista).Buscador =(*(*una_lista).Buscador).Anterior ;
											}
									}
								return NULL ;  // No se encontró el nodo
							}
					}
			}
	}

void elimina (Lista *una_lista , char *nombre )
	{
		Nodo *nodoso = (Nodo*) malloc (sizeof (Nodo)) ;
		nodoso = busca(una_lista,nombre) ;
		if (nodoso !=NULL)
			{
				if ( (*una_lista).longitud > 1)
					{
						if ( son_iguales ( (*una_lista).Inicial , nodoso )  ) //Compara el nodo inicial con el de referencia para reasignar el Inicial
							{
								(*( (*( (*una_lista).Inicial )).Siguiente)).Anterior = NULL ;
								(*una_lista).Inicial = (*nodoso).Siguiente ;
							}
						else
							{
								if ( son_iguales ( (*una_lista).Final , nodoso ) )	//Compara el nodo final con el de referencia para reasignar el final
									{
										(*una_lista).Final = (*nodoso).Anterior ;
										(*( (*una_lista).Final )).Siguiente = NULL ;
									}
								else
									{
										(*((*nodoso).Anterior)).Siguiente = (*nodoso).Siguiente ;
										(*((*nodoso).Siguiente)).Anterior = (*nodoso).Anterior ;
									}
							}
						(*una_lista).longitud -- ;
					}
				else
					{
						(*una_lista).Inicial =NULL ;
						(*una_lista).Final = NULL ;
						(*una_lista).Buscador =NULL;
						(*una_lista).longitud = 0 ;
					}
			}
	}

void agrega ( Lista *una_lista , Nodo *un_nodo ) 
	{
		if ( es_vacia (una_lista) )
			{
				(*una_lista).Inicial = un_nodo;  //apuntando inicial a nodo1 (anterior null ,siguiente null)
				(*una_lista).Final =  un_nodo;  //apuntando final a nodo1 (anterior null siguiente null)
				(*una_lista).longitud = 1 ;
			}
		else
			{
				(*una_lista).Buscador = busca ( una_lista , (*un_nodo).nombre );
				
				if (  (*una_lista).Buscador != NULL) 			// si encuentra un un registro con el mismo nombre...
					{
						if ( son_iguales ( (*una_lista).Buscador , un_nodo )) 				// si son iguales todos los campos, el registro existe 
							printf("\n\nRegistro existente. %s ya existe.", (*un_nodo).nombre);
						else												// si tiene datos diferentes, se agrega antes  del hallado..
							{
								if ( son_iguales ( (*una_lista).Inicial , (*una_lista).Buscador )  ) //Compara el nodo inicial con el de referencia para reasignar el Inicial
									{
										(*un_nodo).Siguiente = (*una_lista).Inicial ;
										(*((*una_lista).Inicial)).Anterior = un_nodo ; 
										(*una_lista).Inicial = un_nodo ;
									}
								else  //Agrega antes del nodo de referencia
									{
										(*un_nodo).Siguiente = (*una_lista).Buscador ;
										(*un_nodo).Anterior = ( *(  (*una_lista).Buscador ) ).Anterior ;
										(*(   ( *( (*una_lista).Buscador  )).Anterior)) .Siguiente = un_nodo ;
										( *(  (*una_lista).Buscador ) ).Anterior   = un_nodo ;
									}
								(*una_lista).longitud ++ ;
							}
					}
				else			// agregar según orden alfabetico ...
					{
						(*una_lista).Buscador = (*una_lista).Inicial ;			//Buscando desde el princicpio
						if ( lexico( (*((*una_lista).Buscador)).nombre , (*un_nodo).nombre)==2) //Busca a la derecha desde donde esté búsqueda
							{  
								while ( lexico( (*((*una_lista).Buscador)).nombre , (*un_nodo).nombre) !=1 && (*una_lista).Buscador != NULL)
									{
										(*una_lista).Buscador = (  *( (*una_lista).Buscador )  ).Siguiente ;
										if ( (*una_lista).Buscador == NULL)
											break;
									}
								(*un_nodo).Siguiente = (*una_lista).Buscador ;
								(*un_nodo).Anterior = ( *(  (*una_lista).Buscador ) ).Anterior ; ;
								(*(   ( *( (*una_lista).Buscador  )).Anterior)) .Siguiente  = un_nodo ;
								( *(  (*una_lista).Buscador ) ).Anterior  = un_nodo ;
								(*una_lista).longitud ++ ;
							}
						else
							{
								if( lexico( (*((*una_lista).Buscador)).nombre , (*un_nodo).nombre)==1) //Busca a la izquierda desde donde esté búsqueda
									{		
										(*un_nodo).Siguiente = (*una_lista).Inicial ;
										(*((*una_lista).Inicial)).Anterior = un_nodo ; 
										(*una_lista).Inicial = un_nodo ;
									}
								(*una_lista).longitud ++ ;
							}
					}
			}
	}
	
void cargar_lista ( Lista *La_lista , char  *archivo ) 
	{
		FILE *cfPtr; 
		if ((cfPtr = fopen(archivo, "r")) == NULL)
			printf("El archivo no se pudo abrir\n");
		else
			{
				while(!feof(cfPtr))
					{
						Nodo *un_nodo = (Nodo*) malloc (sizeof (Nodo)) ;
						(*un_nodo).nombre  = (char*) malloc (sizeof (char ) * 20) ;
						(*un_nodo).tel  = (char*) malloc (sizeof (char ) * 20) ;
						(*un_nodo).correo  = (char*) malloc (sizeof (char ) * 20) ;
						(*un_nodo).Anterior   = (Nodo*) malloc (sizeof (Nodo)) ;
						(*un_nodo).Siguiente = (Nodo*) malloc (sizeof (Nodo)) ;
						(*un_nodo).Anterior   = NULL ;
						(*un_nodo).Siguiente = NULL ;
						fscanf(cfPtr, "%s %s %d %s", (*un_nodo).nombre, (*un_nodo).tel,  &((*un_nodo).edad) , (*un_nodo).correo) ;
						agrega (La_lista , un_nodo ) ;
					}
			}
		fclose(cfPtr);
	}