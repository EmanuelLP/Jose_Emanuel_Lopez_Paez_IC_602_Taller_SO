#include "scheduler.h"

int num_procesos(){
	int num_proc;
	printf("Ingrese la cantidad de procesos a ejecutar\n");
	printf("\tNum procesos= ");
	fflush(stdin);
	scanf("%d",&num_proc);		
	return num_proc;
}

int quantum(){
	int time_ejec;
	printf("Ingrese la cantidad de tiempo que tendra un proceso en ejecucion en la CPU (Seg)\n");
	printf("\tQuantum= ");
	fflush(stdin);
	scanf("%d",&time_ejec);
	return time_ejec;
}

Proceso *llenar_proceso(char *nombre, int tiempo){
	Proceso *proc=(Proceso *)malloc(sizeof(Proceso));
	char *SI="Inicializado";
	strcpy(proc->nombre,nombre);
	proc->tiempo=tiempo;
	strcpy(proc->estado,SI);
	return proc;
}

void imprimir(Proceso vproc[], int num_proc){
	printf("\t\t TABLA DE PROCESOS\n");
	printf("Nombre del proceso |\tTiempo\t|\tEstado\t|\n");
	int i;	
	for(i=0;i<num_proc;i++){
		printf("\t%s\t", vproc[i].nombre);
		printf("\t%d\t", vproc[i].tiempo);
		printf("\t%s\n", vproc[i].estado);
	}	
}

void agregar(Proceso vproc[],Proceso *proc,int posicion){
	strcpy(vproc[posicion].nombre,proc->nombre);
	vproc[posicion].tiempo=proc->tiempo;
	strcpy(vproc[posicion].estado,proc->estado);
}

void llenar_estructura(Proceso vproc[],Proceso *proc,int num_proc){
	char nombre[TAM_TEXTO];
	int tiempo,i;
	for(i=0; i<num_proc; i++){		
		printf("Ingrese el nombre del procesos a ejecutar[%d]\n",(i+1));
		printf("\tNombre: ");
		memset(nombre,'\0',TAM_TEXTO);
		scanf("%s",nombre);
		printf("Ingrese la cantidad de tiempo del  proceso a ejecutar (Seg)\n");
		printf("\tTiempo= ");
		fflush(stdin);
		scanf("%d",&tiempo);
		proc=llenar_proceso(nombre,tiempo);
		agregar(vproc,proc,i);		
	}

}

bool vector_finalizado(Proceso vproc[],int num_proc){
	bool bandera;
	int i,cn=0;
	for(i=0;i<num_proc;i++){
		if(vproc[i].tiempo == 0 && strcasecmp(vproc[i].estado,"Finalizado")==0 ){
			cn++;
		}
	}
	if(cn==num_proc){
		printf("\nSimulacion terminada");
		bandera=true;
	}else{
		bandera=false;
	}
	return bandera;
}

void imprimir_posicion(Proceso vproc[], int posicion){
	printf("\n\t%s\t", vproc[posicion].nombre);
	printf("\t%d\t", vproc[posicion].tiempo);
	printf("\t%s\n", vproc[posicion].estado);
}


void round_robin(Proceso vproc[], int time_ejec,int num_proc){
	int i=0,time_cpu=0;
	bool bandera;
	char *SE="Ejecucion",*SB="Bloqueado",*SF="Finalizado";
	do{
		if(strcasecmp(vproc[i].estado,"Inicializado") == 0 ){
				imprimir_posicion(vproc,i);
		}
		bandera=vector_finalizado(vproc,num_proc);
		if(bandera==false){									
			if(strcasecmp(vproc[i].estado,"Finalizado") == 0 ){
				i++;
			}
			if(vproc[i].tiempo > 0){
				strcpy(vproc[i].estado,SE);
				imprimir_posicion(vproc,i);
			}			
			if(vproc[i].tiempo > 0 && vproc[i].tiempo >= time_ejec){			
				vproc[i].tiempo=vproc[i].tiempo-time_ejec;
				if(vproc[i].tiempo == 0){
					strcpy(vproc[i].estado,SF);
				}
				if(vproc[i].tiempo > 0){
					strcpy(vproc[i].estado,SB);
				}
				time_cpu=time_cpu+time_ejec;
			} else if(vproc[i].tiempo > 0 && vproc[i].tiempo < time_ejec){
				vproc[i].tiempo=0;
				strcpy(vproc[i].estado,SF);
				time_cpu=time_cpu+vproc[i].tiempo;
			}			
			imprimir_posicion(vproc,i);	
		}
		i++;	
		if(i==num_proc){
			i=0;	
		}
	}while(bandera==false);	
	printf("\nEl tiempo en la CPU fue %d\n",time_cpu);
}

