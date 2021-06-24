#ifndef __scheduler
#define __scheduler

#include <stdio.h>
#include <stdlib.h>
//Para usar variables tipo boolean
#include <string.h>
#include <stdbool.h>

#define TAM_TEXTO 50

typedef struct {
	char nombre[TAM_TEXTO];
	int tiempo;
	char estado[TAM_TEXTO];
}Proceso;

int num_procesos();

int quantum();

Proceso *llenar_proceso(char *nombre, int tiempo);

void imprimir(Proceso vproc[], int num_proc);

void agregar(Proceso vproc[],Proceso *proc,int posicion);

void llenar_estructura(Proceso vproc[],Proceso *proc,int num_proc);

bool vector_finalizado(Proceso vproc[],int num_proc);

void imprimir_posicion(Proceso vproc[], int posicion);


void round_robin(Proceso vproc[], int time_ejec,int num_proc);


#endif

