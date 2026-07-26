#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *sig;
	struct nodo *ant;
};

struct nodo *primero=NULL;
struct nodo *ultimo=NULL;

void insertar ();
void buscar ();
void eliminar ();
void modificar ();
void mostrar ();

int main (){
	
	int op;
	
	do{
		printf("Que operacion realizaras\n");
		printf("1) Insertar\n");
		printf("2) Buscar\n");
		printf("3) Eliminar\n");
		printf("4) Modificar\n");
		printf("5) Mostrar\n");
		printf("6) Salir\n");
		scanf("%d", &op);
		
		switch(op){
			
			case 1:
				insertar();
				break;
				
				case 2:
				buscar();
				break;
				
				case 3:
				eliminar();
				break;
				
				case 4:
				modificar();
				break;
				
				case 5:
				mostrar();
				break;
				
				default:
				printf("\nADIOS");
				break;
		}
	}while(op<6);
}

void insertar(){
	struct nodo *nuevo;
	nuevo=(nodo*)malloc(sizeof(nodo));
	
	printf("Ingresa el dato");
	scanf("%d", &nuevo->dato);
	
	if(primero==NULL){
		primero=nuevo;
		primero->sig=NULL;
		primero->ant=NULL;	
	}
	else
		ultimo->sig=nuevo;
		nuevo->sig=NULL;
		nuevo->ant=ultimo;
		ultimo=nuevo;
	
}


void buscar(){
	struct nodo *actual;
	int nodoBuscado;
	int encontrado=0;
	actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	printf("\nDato a buscar\n");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual!=NULL&&encontrado!=1){
			if(actual->dato==nodoBuscado){
				printf("\nSe a encontardo el dato %d\n", actual->dato);
				encontrado=1;
			}
			actual=actual->sig;
		}
		if(encontrado==0){
			printf("\nNo existe el dato");
			}
		}
	else 
		{
		printf("\nLa lista esta vacia");
		}
	}

void modificar(){
	struct nodo *actual;
	int nodoBuscado;
	int encontrado=0;
	actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	printf("\nDato a buscar\n");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual!=NULL&&encontrado!=1){
			if(actual->dato==nodoBuscado){
				printf("\nSe a encontardo el dato: %d\n", actual->dato);
				encontrado=1;
				printf("\nIngresa el nuevo dato\n");
				scanf("%d", &actual->dato);
			}
		}
		if(encontrado==0)
		printf("\nNo existe el dato");
	}
	else{
		printf("\nLa lista esta vacia");
	}
}

void eliminar(){
	nodo *actual;
	actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	nodo *ant2;
	ant2=(nodo*)malloc(sizeof(nodo));
	ant2=NULL;
	
	int nodoBuscado;
	int encontrado=0;
	
	if(primero!=NULL){
	
		printf("\nIngresa el dato a buscar para eliminarlo\n");
		scanf("%d", &nodoBuscado);
	
		while(actual!=NULL&&encontrado!=1){
			if(actual->dato==nodoBuscado){
				if(actual==primero){	
				primero=primero->sig;
				primero->ant=NULL;
			}
			else if(actual==ultimo){
				ant2->sig=NULL;
				ultimo=ant2;
			}else{
				ant2->sig=actual->sig;
				actual->sig->ant=ant2;
			}
			printf("\nNodo eliminado con exito");
			encontrado=1;
	}
		ant2=actual;
		actual=actual->sig;
}
	if(encontrado==0){
			printf("Nodo no enconrado");
	}
		else{
			free(ant2);
	}
}
else{
	printf("La lista esta vacia");
}
}

void mostrar(){
	nodo *actual;
	actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		while (actual!=NULL){
			printf("\n%d",actual->dato);
			actual=actual->sig;
		}
		
	}
	else{
		printf("\nLa lista esta vacia");
	}
}
