#include "../Cadenas/Cadenas.h"
#include <stdio.h>

// Estructuras:

typedef struct Nodo Nodo ;
typedef struct Arbol Arbol ;

struct Arbol 
	{
		Nodo *Raiz ;
		Arbol *Hijo_izquierdo, *Hijo_derecho ;
	} ;
	
struct Nodo 
	{
		char Nombre ;
		int Indice  ;
	} ;
	

//Funciones de recorrido 

void Pre_Orden ( Arbol* ) ;
void In_Orden ( Arbol* ) ;
void Post_Orden ( Arbol* ) ; 


//Funciones estándar

void Sembrar ( Arbol * ) ; 						// Inicializa objeto  --> Listo
				
void Talar ( Arbol* ) ;			 					// Libera memoria de cada nodo hasta la raíz  del árbol recibido--> Pendiente
				
int es_vacio ( Arbol* ) ; 							// 1: vacío. 0: no vacío  --> Listo
				
Nodo* Ver_Raiz ( Arbol* ) ; 					// Regresa la posición (apuntador) de la raíz del árbol  --> Listo 

Nodo* Busca_nodo ( Arbol* , char  ) ;  	//Regresa la posición (apuntador) del nodo buscado  --> Listo

	Nodo* Nodo_padre ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del padre del nodo argumento				 --> Listo
	Nodo* Hijo_izquierdo ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del hijo izquierdo del nodo argumento    --> Listo
	Nodo* Hijo_derecho  ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del hijo derecho del nodo argumento      --> Listo

void Leer_nodo ( Arbol* , Nodo* ) ; 		// Muestra en pantalla el nombre del nodo, sus hijos, su padre y el nivel en que se encuentra --> Listo

void Nuevo_hijo ( Arbol* , Nodo* ) ; 		// Inserta el nuevo nodo en el árbol según criterio de ordenamiento ---> Listo

Arbol* Eliminar_nodo ( Arbol* , Nodo* ) ; // Elimina un nodo en el árbol y recorre los nodos --> Listo

// Funciones de equilibrio ....

int mide_arbol( Arbol* ) ;    // Regresa la altura del árbol --> Listo
int Calcula_indice ( Arbol* ) ;  // Calcula índice de equilibrio del nodo raíz del árbol, restando altura del sub_derecho menos  sub_izquierdo --> Listo
Arbol* Rotacion_I (Arbol* , char );  // Realiza las rotaciones correspondientes -->Listo
Arbol* Rotacion_II (Arbol* , char ); // Realiza las rotaciones correspondientes -->Listo 
Arbol* Equilibra (Arbol* , Nodo* );   // Calcula los índices de equilibrio y procede a equilibrar en caso de ser necesario --> Listo

Arbol* Padre_de ( Arbol* , Nodo*) ; // Mismo algoritmo de Nodo_padre ( Arbol* , Nodo* ) pero que regresa un árbol -->Listo

Nodo* Busca_nodo_r (Arbol* , char ) ; // Mismo algoritmo que Busca_nodo () imprimiendo la ruta que sigue .---> Listo