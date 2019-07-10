#include <stdio.h>
#include <stdlib.h>



#include "Funcioneslab05.h"



int main(){
	
	Arbol *Arbol_lleno;
	int altura=-1,max=0,posicion=0,altura_aux=0;
	char direccion[]="secuencia.txt";
	if(AbrirArchivo(direccion)){
		printf("\n-Archivo abierto correctamente\n\n");
	}else{
		printf("Error al abrir el archivo\n");
	}
	Arbol_lleno=CreaArbol(direccion);
	altura=CalculaAltura(Arbol_lleno,altura,max);
	printf("La altura es :%i\n",altura);
	altura_aux=altura+1;//Agrega el nivel de nulos extra
	altura=(pow(2,altura+2)-1);
	char *punteroArreglo=malloc(altura*sizeof(int));
	vaciarArreglo(altura,punteroArreglo);
 	CreaArbolEnArreglo(Arbol_lleno,punteroArreglo,posicion);
 
 	int i;
 	for(i=0;i<altura;i++){
 		if(punteroArreglo[i]=='\0'){
 			printf("0");
 		}else{
 		printf("%c",punteroArreglo[i]);
 	}
 	
 	}
 	//RellenaNulos(punteroArreglo);
	//imprimir(Arbol_lleno);
	printf("\nArbol:\n\n\n");
	muestraArbolEnTerminal(punteroArreglo,altura_aux);
	return 0;
	
}
