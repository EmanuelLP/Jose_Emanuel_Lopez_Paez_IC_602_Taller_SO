#include "scheduler.h"


void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

int main(int argc, char const *argv[]){

	//Creacion de llamadas al hilo
	pthread_t h1;
	pthread_t h2;
	pthread_t h3;
	pthread_t h4;
	pthread_t h5;
	pthread_t h6;
	pthread_t h7;
	pthread_t h8;
	pthread_t h9;
	
	process p1 = {1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO}; 		//<--
	process p2 = {1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO};
	process p3 = {3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO}; 	//<--
	process p4 = {4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO};   	//<--
	process p5 = {3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO};		
	process p6 = {4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO};
	process p7 = {0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO};	//<--	
	process p8 = {2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO};		//<--
	process p9 = {5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO};	//<--
	
	//Crear hilo

	pthread_create(&h1,NULL,(void *)crear_Proceso,&p1);
	pthread_create(&h2,NULL,(void *)crear_Proceso,&p2);	
	pthread_create(&h3,NULL,(void *)crear_Proceso,&p3);	
	pthread_create(&h4,NULL,(void *)crear_Proceso,&p4);	
	pthread_create(&h5,NULL,(void *)crear_Proceso,&p5);	
	pthread_create(&h6,NULL,(void *)crear_Proceso,&p6);	
	pthread_create(&h7,NULL,(void *)crear_Proceso,&p7);	
	pthread_create(&h8,NULL,(void *)crear_Proceso,&p8);	
	pthread_create(&h9,NULL,(void *)crear_Proceso,&p9);	
		
	
	//Ejecutar hilo
	pthread_join(h1,NULL);
	pthread_join(h2,NULL);
	pthread_join(h3,NULL);
	pthread_join(h4,NULL);
	pthread_join(h5,NULL);
	pthread_join(h6,NULL);
	pthread_join(h7,NULL);
	pthread_join(h8,NULL);
	pthread_join(h9,NULL);

	
	array_procesos *array = crear_ArrayProcesos();
	
	
	agregar_Proceso(array, p1);
	agregar_Proceso(array, p2);
	agregar_Proceso(array, p3);
	agregar_Proceso(array, p4);
	agregar_Proceso(array, p5);
	agregar_Proceso(array, p6);
	agregar_Proceso(array, p7);
	agregar_Proceso(array, p8);
	agregar_Proceso(array, p9);

	ejecutar_Procesos(array);
	free(array);
	/*free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);*/

	return 0;
}

void reproducir_musica(void){
	printf("Reproduciendo Música\n");
}

void abrir_youtube(void){
	printf("Usando Youtube\n");
}

void escribir_texto_word(void){
	printf("Escribiendo Texto en Word\n");
}

void descargar_archivo(void){
	printf("Descargando Archivo\n");
}

void subiendo_archivo(void){
	printf("Subiendo Archivo\n");
}

void compilando_programa(void){
	printf("Compilando programa\n");
}

void ejecutando_programa(void){
	printf("Ejecutando programa\n");
}

void usando_terminal(void){
	printf("Usando la terminal\n");
}


