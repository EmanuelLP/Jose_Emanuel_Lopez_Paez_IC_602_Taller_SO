#include "scheduler.h"

int main(){

//Datos iniciales
	int num_proc=num_procesos();
	int time_ejec=quantum();
	
//Lenado de las estrcturas de procesos
	Proceso *proc;
	Proceso vproc[num_proc];
	llenar_estructura(vproc,proc,num_proc);
//Tabla de procesos entrada
	imprimir(vproc,num_proc);
//Ejecucion multiprogramacion (Round Robin)
	printf("\t\t EJECUCION DE PROCESOS\n");
	printf("Nombre del proceso |\tTiempo\t|\tEstado\t|\n");
	round_robin(vproc,time_ejec,num_proc);	
return 0;
}
