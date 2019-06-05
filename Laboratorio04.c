#include <stdio.h>
#include <stdlib.h>

#include "FuncionesLab04.h"

int main(){
	
	Arbol *Arbol_lleno;
	char caracter_leido;
	char direccion[]="secuencia.txt";
	if(AbrirArchivo(direccion)){
		printf("\n-Archivo abierto correctamente\n\n");
	}else{
		printf("Error al abrir el archivo\n");
	}
//	LeerArchivo(direccion);
	Arbol_lleno=CreaArbol(direccion);
	printf("\n\nArbol Creado");
	
	
}
