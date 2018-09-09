#include "../Cadenas/Lexico.h"

typedef struct Nodo Nodo ;
typedef struct Lista Lista ;

struct Nodo 
	{
		int edad ;
		char *nombre, *tel, *correo;
		Nodo *Anterior, *Siguiente ;
	} ;
struct Lista 
	{
		int longitud ;
		Nodo *Inicial, *Final, *Buscador ;
	} ;

int es_vacia ( Lista* ) ;													
void imprime_lista ( Lista* ) ;															
void cargar_lista ( Lista* , char*  ) ;
void agrega ( Lista* , Nodo*) ;	                     
void elimina ( Lista* , char* ) ;                                       
Nodo* busca ( Lista* , char* ) ;

//Funciones extra : 
void crea_nodo ( Nodo* ) ;	
void crea_lista ( Lista* )  ;	
int son_iguales (Nodo* , Nodo*);