#include "scheduler.h"

void *reproducir_musica(void * params);
void *abrir_youtube(void * params);
void *escribir_texto_word(void * params);
void *descargar_archivo(void * params);
void *subiendo_archivo(void * params);
void *compilando_programa(void * params);
void *ejecutando_programa(void * params);
void *usando_terminal(void * params);

int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

void *reproducir_musica(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Reproduciendo Música\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *abrir_youtube(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Usando Youtube\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *escribir_texto_word(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Escribiendo Texto en Word\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *descargar_archivo(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Descargando Archivo\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *subiendo_archivo(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Subiendo Archivo\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *compilando_programa(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Compilando programa\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *ejecutando_programa(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Ejecutando programa\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}

void *usando_terminal(void * params){
	char *nombre_proceso;
	nombre_proceso = (char *)params;
	printf("Usando la terminal\n");
	printf("\t ======> EJECUTANDO PROCESO: [%s]\n", nombre_proceso);
	pthread_exit(NULL);
}
