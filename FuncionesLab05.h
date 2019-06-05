#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	caracter=fgetc(archivo);
	if(caracter=='N'){
		return NULL;
	}else{
		int dato=caracter-'0';
		Arbol *Nuevo_nodo;
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
		auxArbol = recorreArbol(archivo); 
		if(auxArbol==NULL){
			printf("Arbol Nulo");
		}
		fclose(archivo);
		return auxArbol;
		
}

int CalculaAltura(Arbol *Arbol_lleno,int altura,int max){//Calcula la distancia al nodo mas lejano, asi calculo la cantidad de nodos maximo en un arbol binario

	if(Arbol_lleno==NULL){
		if(altura>max){
			max=altura;
			altura=0;	
			return max;
		}else{
			return;
	}
}

	max=CalculaAltura(Arbol_lleno->hizq,altura=altura+1,max);
	max=CalculaAltura(Arbol_lleno->hder,altura=altura+1,max);
	return max;
		
}

int imprimir(Arbol *Arbol_lleno){//Funcion que imprimia el arreglo para verificar si todo estaba correcto
	
	if(Arbol_lleno==NULL){
		printf("Dato=Nulo\n");
		return -1;
	}
	
	printf("Dato %c\n",Arbol_lleno->dato);
	imprimir(Arbol_lleno->hizq);
	imprimir(Arbol_lleno->hder);
		return 0;
		
}

void vaciarArreglo(int altura,char punteroArreglo[altura]){//Dejo el arreglo con espacios en blanco para que no haya error
	
	int i=0;
	while(i<altura){
		punteroArreglo[i]='\0';
		i++;
	}
}

void CreaArbolEnArreglo(Arbol *Arbol_lleno,char *punteroArreglo ,int posicion){
	
	if(Arbol_lleno==NULL){
		punteroArreglo[posicion]='N';
		return;
	}
	
	punteroArreglo[posicion] = Arbol_lleno->dato;
	CreaArbolEnArreglo(Arbol_lleno->hizq,punteroArreglo,2*posicion+1);		
    CreaArbolEnArreglo(Arbol_lleno->hder,punteroArreglo,2*posicion+2);
	return;
			
}

int RellenaNulos(char *punteroArreglo){
	
	int i=0;
	for(i;i<32;i++){
		if(punteroArreglo[i]=='\0'){
			punteroArreglo[i]='N';
		}
	}
}

void muestraArbolEnTerminal(char *punteroArreglo){
	
	int indice=0,contador=0;
	int nivel[5]={0,1,2,3,4};//Los distintos niveles del Arbol
	for(indice;indice<5;indice++){
	fflush(stdin);
	int nodos_total=0,nodos_inicio=0,nodos_nivel=0;
	nodos_total=(pow(2,nivel[indice]+1)-1);//Nodos totales hasta cierto nivel
	nodos_inicio=nodos_total-(pow(2,nivel[indice]));//Desde que numero hasta la cantidad de nodos en un nivel tiene que recorrer el indice
	nodos_nivel=nodos_total-nodos_inicio;//La cantidad de nodos que hay en un nivel

	//Impresion en la consola
	for(contador=nodos_inicio;contador<nodos_nivel;contador++){
		if(nodos_total==1){
			printf("                                               %c         \n",punteroArreglo[contador]);
			printf("                                               |         \n");
			
		}
		if(nodos_total==3){
			printf("                            %c-------------------------------------%c\n",punteroArreglo[contador],punteroArreglo[nodos_total-contador]);
			printf("                            |                                     |\n");
		}
		if(nodos_total==7){
			printf("                  %c-------------------%c                 %c-------------------%c\n",punteroArreglo[contador],punteroArreglo[nodos_total-contador],punteroArreglo[nodos_total-contador+1],punteroArreglo[nodos_total-contador+2]);
			printf("                  |                   |                 |                   |\n");
		}
		if(nodos_total==15){
			printf("            %c-----------%c       %c-----------%c     %c-----------%c       %c-----------%c\n",punteroArreglo[contador],punteroArreglo[nodos_total-contador],punteroArreglo[nodos_total-contador+1],punteroArreglo[nodos_total-contador+2],punteroArreglo[nodos_total-contador+3],punteroArreglo[nodos_total-contador+4],punteroArreglo[nodos_total-contador+5],punteroArreglo[nodos_total-contador+6]);
			printf("            |           |       |           |     |           |       |           |\n");
		}
		if(nodos_total==31){
			printf("         %c-----%c     %c-----%c %c-----%c     %c----%c %c----%c     %c-----%c %c-----%c     %c-----%c\n",punteroArreglo[contador],punteroArreglo[nodos_total-contador],punteroArreglo[nodos_total-contador+1],punteroArreglo[nodos_total-contador+2],punteroArreglo[nodos_total-contador+3],punteroArreglo[nodos_total-contador+4],punteroArreglo[nodos_total-contador+5],punteroArreglo[nodos_total-contador+6],punteroArreglo[nodos_total-contador+7],punteroArreglo[nodos_total-contador+8],punteroArreglo[nodos_total-contador+9],punteroArreglo[nodos_total-contador+10],punteroArreglo[nodos_total-contador+11],punteroArreglo[nodos_total-contador+12],punteroArreglo[nodos_total-contador+13],punteroArreglo[nodos_total-contador+14]);
		}
	}
}
	return;
}






