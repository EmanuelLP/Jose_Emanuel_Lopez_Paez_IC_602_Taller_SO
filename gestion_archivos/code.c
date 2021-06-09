#include <stdio.h>
#include <string.h>

#define TAM_NOMBRE 100
#define TAM_LECTURA 100

#define MAXIMA_LONGITUD_CADENA 1000

FILE *abrir_Archivo_solo_Lectura(char *nombre_arch){
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo == NULL ){
		// con r Abre un archivo para lectura.
		printf("---> El archivo -> %s <- NO pudo abrirse (uso de r).\n", nombre_arch);
	}	
	else{
		printf("---> Archivo -> %s <- Abierto (uso de r).\n", nombre_arch);
	}
	return ptrArchivo;
}

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", nombre_arch);
}


int existe_archivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 0;
	// Con r abre un archivo para lectura.
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}

FILE *abrir_Archivo_lectura_escritura(char *nombre_arch){
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "r+");
	if( ptrArchivo == NULL ){
		// con r+ Abre un archivo para actualización (lectura y escritura).
		printf("---> El archivo -> %s <- NO pudo abrirse (uso de r+).\n", nombre_arch);
	}	
	else{
		printf("---> Archivo -> %s <- Abierto (uso de r+).\n", nombre_arch);
	}
	return ptrArchivo;
}

// Implementación del método de la burbuja en C, para arreglos de cadenas
void burbuja(char arreglo[][MAXIMA_LONGITUD_CADENA], int longitud)
{
    // Útil para hacer intercambio de cadenas
    char temporal[MAXIMA_LONGITUD_CADENA];
    int x, indiceActual;
    for (x = 0; x < longitud; x++)
    {
        for (indiceActual = 0; indiceActual < longitud - 1;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            // Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
            if (strcmp(arreglo[indiceActual], arreglo[indiceSiguienteElemento]) > 0)
            {
                // Movemos la cadena actual a la temporal
                memcpy(temporal, arreglo[indiceActual], MAXIMA_LONGITUD_CADENA);
                // Movemos al actual el siguiente elemento
                memcpy(arreglo[indiceActual], arreglo[indiceSiguienteElemento], MAXIMA_LONGITUD_CADENA);
                // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
                memcpy(arreglo[indiceSiguienteElemento], temporal, MAXIMA_LONGITUD_CADENA);
            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}



int main(int argc, char const *argv[]){
	// FILE es una estructura
	/*  ptrCF apuntado al archivo
	Open apuntador que si no puede abrir el programa se cierra*/
	FILE *ptrCf = NULL;
	char nom_archivo[TAM_NOMBRE];
	int existe_arch = 0;
	char cadena[TAM_LECTURA];
	char cadena1[TAM_LECTURA];
	char separadores[]=" \n\t";
	char *puntero;
	int palabras=0;
	//VERIFICACION DE UN ARCHIVO EXISTENTE
	do{
		printf("\tIntroduzca el Nombre del Archivo de Entrada: ");
		gets(nom_archivo);
		existe_arch = existe_archivo(nom_archivo);
		if(existe_arch){
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <-EXISTE.\n", nom_archivo);
			printf("---------------------------------------------------------------\n");
		}else{
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <- NO EXISTE.\n", nom_archivo);
			printf("---------------------------------------------------------------\n");
		}
	}while(!existe_arch);	
	//ABRIR ARCHIVO 	
	ptrCf = abrir_Archivo_solo_Lectura(nom_archivo);
	if(ptrCf == NULL){
		printf("****************************************************************\n");
		printf("\tEl archivo -> %s <- NO pudo Abrirse.\n", nom_archivo);			
		printf("****************************************************************\n");
	}
	else{
		printf("****************************************************************\n");
		printf("\tArchivo -> %s <- Abierto Correctamente.\n", nom_archivo);			
		printf("****************************************************************\n");
		while(!feof(ptrCf)){
			fgets(cadena,TAM_LECTURA,ptrCf);
			printf("%s",cadena);
		}			
		printf("---------------------------------------------------------------------------\n");
		printf("\t---> LECTURA TERMINADA <---\n");					
		printf("---------------------------------------------------------------------------\n");
		cerrar_archivo(ptrCf, nom_archivo);
	}
	//NUMERO PALABRAS PALABRAS
	printf("****************************************************************\n");
	printf("\tPalabras separadas\n");			
	printf("****************************************************************\n");
	ptrCf = abrir_Archivo_solo_Lectura(nom_archivo);
	//setear la cadena con el valor 0=\0 es vacio
	memset(cadena1,0,TAM_LECTURA);
	while(!feof(ptrCf)){
		fgets(cadena1,TAM_LECTURA,ptrCf);
		/*strtok=token particionar la cadena por separadores*/
		puntero=strtok(cadena1,separadores);
		palabras++;
		strcpy(cadena1,puntero);
		printf("%s\n",cadena1);
		while((puntero=strtok(NULL,separadores))!=NULL){
			palabras++;
			strcpy(cadena1,puntero);
			printf("%s\n",cadena1);
		}	
	}				
	cerrar_archivo(ptrCf, nom_archivo);
	

	int contador=0;
	char texto[palabras][MAXIMA_LONGITUD_CADENA];
	char buffer[MAXIMA_LONGITUD_CADENA];
	//LLENAR VECTOR DE PALABRAS
	
	ptrCf = abrir_Archivo_lectura_escritura(nom_archivo);
	while(fgets(buffer,MAXIMA_LONGITUD_CADENA,ptrCf)){
		strtok(buffer,"\n");
		memcpy(texto[contador],buffer,MAXIMA_LONGITUD_CADENA);
		contador++;
	}
			
	cerrar_archivo(ptrCf, nom_archivo);
	
	
	
	int longitud = sizeof(texto) / sizeof(texto[0]);
 	// Imprimimos el arreglo antes de ordenarlo, solo para ilustrar
 	printf("---Imprimiendo arreglo sin ordenar---\n");
 	int i;
 	for (i = 0; i < longitud; i++){
       	printf("%s\n", texto[i]);
	}	
	    
	// Lo ordenamos
	burbuja(texto, longitud);
	// Volvemos a imprimir
	printf("---Imprimiendo arreglo ordenado---\n");
	for (i = 0; i < longitud; i++){
        	printf("%s\n", texto[i]);
    	} 
	    
    
	
return 0;
}
