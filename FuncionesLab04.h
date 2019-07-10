#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
	int dato;
	struct _nodo *hizq,*hder;
}Arbol;


int AbrirArchivo(char direccion[]){
	
	FILE *archivo;
	archivo=fopen(direccion,"r");
		if(archivo==NULL){
			return 0;
		}else{
		return 1;
		}
	fclose(archivo);
	
}

int LeerArchivo(char direccion[]){
	
		FILE *archivo;
		char caracter_leido;
		archivo=fopen(direccion,"r");
		if (archivo==NULL){
            printf("\nError de apertura del archivo. \n\n");
            return 0;
        }else{
		while((caracter_leido=fgetc(archivo))!=EOF){
			printf("%c",caracter_leido);
		}}
		fclose(archivo);
		return 1;
}

Arbol *CrearNodo(char caracter){
	
	Arbol *nuevo;
	nuevo=malloc(sizeof(Arbol));
	nuevo->dato=caracter;
	nuevo->hizq=NULL;
	nuevo->hder=NULL;
	return nuevo;
	
}

Arbol *recorreArbol(FILE *archivo){
	
	char caracter;
	Arbol *Nuevo_nodo;
	caracter=fgetc(archivo);
	printf("%c",caracter);
		if(caracter=='N'){
			return NULL;
		}else{	
			Nuevo_nodo=CrearNodo(caracter);
			Nuevo_nodo->hizq=recorreArbol(archivo);
			Nuevo_nodo->hder=recorreArbol(archivo);
			return Nuevo_nodo;
		}
	
}

Arbol *CreaArbol(char direccion[]){
	
		FILE *archivo;
		archivo=fopen(direccion,"r");
		Arbol *auxArbol;
		printf("Secuencia:\n");
		auxArbol = recorreArbol(archivo); 
		fclose(archivo);
		return auxArbol;
		
}

