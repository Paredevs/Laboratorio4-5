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

/*int RellenaNulos(char *punteroArreglo){
	
	int i=0;
	for(i;i<32;i++){
		if(punteroArreglo[i]=='\0'){
			punteroArreglo[i]='N';
		}
	}
}*/

void muestraArbolEnTerminal(char *punteroArreglo,int altura){
	
	int indice,separacion=85;
	for(indice=0;indice<=altura;indice++){
	fflush(stdin);
	int nodos_total=0,nodos_inicio=0,nodos_nivel=0;
	nodos_total=(pow(2,indice+1)-1);//Nodos totales hasta cierto nivel
	nodos_inicio=nodos_total-(pow(2,indice));//Desde que numero hasta la cantidad de nodos en un nivel tiene que recorrer el indice
	nodos_nivel=nodos_total-nodos_inicio;//La cantidad de nodos que hay en un nivel	
	int separaciones=nodos_nivel/2;
	
	if(indice==0){
		EscribeEspacios(separacion);//Primer espacio nivel 0
		printf("%c",punteroArreglo[nodos_inicio]);
		EscribeEspacios(separacion);//Segundo espacio nivel 0
		salto();
	}else{
		separacion=separacion/2;
		EscribeEspacios(separacion);//Primer espacio siguentes niveles
		ImprimeArreglo(nodos_total,nodos_inicio,punteroArreglo,separacion);
		EscribeEspacios(separacion);//Segundo espacio siguentes niveles
		salto();
	}

}	
return;
}

ImprimeArreglo(int nodos_total,int nodos_inicio,char *punteroArreglo,int separacion){
	
	for(nodos_inicio;nodos_inicio<nodos_total;nodos_inicio++){
		if(punteroArreglo[nodos_inicio]!='\0'){
			fflush(stdin);
			if(nodos_inicio%2!=0){
				printf("%c",punteroArreglo[nodos_inicio]);
				AgregaLineas(separacion);
			}
			if(nodos_inicio%2==0){
				printf("%c",punteroArreglo[nodos_inicio]);
				EscribeEspacios(separacion+(separacion/2+6));
			}
		}else{
			EscribeEspacios(separacion*3+4);
			nodos_inicio++;
		}
	}
	
}

int EscribeEspacios(int separacion){
	
	int i=1;
	for(i;i<=separacion;i++){
		printf(" ");
	}
	return separacion;
}

int AgregaLineas(int separacion){
		
		int i;
		for(i=1;i<=separacion-2;i++){
			printf("-");
		}
		printf("/");
		printf(" ");
		printf("\\");
		for(i=1;i<=separacion-2;i++){
			printf("-");
		}
		return;	
	
}

int salto(){
	
	printf("\n");
	
}




