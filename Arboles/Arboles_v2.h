#include <stdio.h>
#include "Arbol.h"
#include "../Cadenas/Cadenas.h"

//Funciones estándar

void Sembrar ( Arbol * ) ; 						// Inicializa objeto  --> Listo
				
void Talar ( Arbol* ) ;			 					// Libera memoria de cada nodo hasta la raíz  --> Pendiente
				
int es_vacio ( Arbol* ) ; 							// 1: vacio. 0: no vacio  --> Listo
				
Nodo* Ver_Raiz ( Arbol* ) ; 					// Regresa la posición (apuntador) de la raíz del árbol  --> Listo 

Nodo* Busca_nodo ( Arbol* , char  ) ;  	//Regresa la posición (apuntador) del nodo buscado  --> Listo

	Nodo* Nodo_padre ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del padre del nodo argumento				 --> Listo
	Nodo* Hijo_izquierdo ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del hijo izquierdo del nodo argumento    --> Listo
	Nodo* Hijo_derecho  ( Arbol* , Nodo* ) ;	//Regresa la posición (apuntador) del hijo derecho del nodo argumento      --> Listo

void Leer_nodo ( Arbol* , Nodo* ) ; 		// Muestra en pantalla el nombre del nodo, sus hijos, su padre y el nivel en que se encuentra --> Listo

void Nuevo_hijo ( Arbol* , Nodo* ) ; 		// Inserta el nuevo nodo en el árbol según criterio de ordenamiento ---> Listo

//void Eliminar_nodo ( Arbol* , Nodo* ) ;
//void Reemplazar_nodo ( Arbol* , Nodo* ) ;