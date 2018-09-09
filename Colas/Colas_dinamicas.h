#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento Elemento ;
typedef struct Cola Cola ;

struct Elemento {		char valor ;   	} ;
struct Cola {		Elemento *elementos ;			int longitud ; 	} ;

void Inicializa_cola ( Cola*) ;
int is_empty ( Cola* ) ;
void push ( Cola* , char );
void imprime_cola ( Cola* ) ;
char pop ( Cola* ) ;