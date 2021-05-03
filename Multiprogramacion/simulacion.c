#include <stdio.h>
#include <stdlib.h>
//Para usar variables tipo boolean
#include <string.h>
#include <math.h>
typedef struct {
	char nombre[20];
	int tiempo;
	char estado[20];
}Proceso;
typedef struct {
	char nombre[20];
	int tiempo;
	char estado[20];
	int gantt;
}DGantt;
int main(){
//Datos iniciales
	int num_proc, time_ejec;
	printf("Ingrese la cantidad de tiempo que tendra un proceso en ejecucion en laPU (Seg)\n");
	printf("Quantum= ");
	fflush(stdin);
	scanf("%d",&time_ejec);
	printf("Ingrese la cantidad de procesos a ejecutar\n");
	printf("Num procesos= ");
	fflush(stdin);
	scanf("%d",&num_proc);	
//Lenado de las estrcturas deprocesos
	Proceso proc[num_proc];
	int i;
	char *SI,*SE,*SF,*SB;
	for(i=0; i<num_proc; i++){
		printf("Ingrese el nombre del procesos a ejecutar[%d]\n",(i+1));
		printf("Nombre: ");
		fflush(stdin);
		gets(proc[i].nombre);
		printf("Ingrese la cantidad de tiempo del  proceso a ejecutar (Seg)\n");
		printf("Tiempo= ");
		fflush(stdin);
		scanf("%d",&proc[i].tiempo);
		SI="Inicializado";
		strcpy(proc[i].estado,SI); 	
	}
	//Tabla de procesos
	printf("\t\t TABLA DE PROCESOS\n");
	printf("Nombre del proceso |\tTiempo\t|\tEstado\t|\n");	
	for(i=0;i<num_proc;i++){
		printf("\t%s\t", proc[i].nombre);
		printf("\t%d\t", proc[i].tiempo);
		printf("\t%s\n", proc[i].estado);
	}	
//Simulacion multiprogramacion (Método Round Robin)	[tamaño de tabla]
	int bandera=0,j=0,contador=0,time_act,k=0;
	int suma=0,total=0, l=0, tm=0, cn=0;
	Proceso temporal[num_proc];
	//Llenamos un array temporal
	for(i=0;i<num_proc;i++){
		temporal[i]=proc[i];
	}
	//Determinacion del tamaño del segundo vector
	do{
		//Se verifica que todos los valores en tiempo, for para recorrer  
		//if para que el tiempo sea <= 0 y que este se ejecute hasta la ultima 
		//posicion del array
		for(i=0;i<num_proc;i++){
			if(temporal[i].tiempo <= 0 && (l+1)==num_proc ){
				cn++;
			}
		}
		if(temporal[l].tiempo>0){
			total++;
			tm=temporal[l].tiempo-time_ejec;
			temporal[l].tiempo=tm;
		}
		if((l+1)==num_proc){
			l=0;
			suma++;
		}else{
			l++;
		}
		if(cn==num_proc){
			bandera=1;
		}
	}while(bandera==0);
	int tam;
	tam=(total+suma)+(num_proc*3);
//Simulacion multiprogramacion (Método Round Robin)	[Estados y tiempo ]
	i=0;
	cn=0;
	bandera=0;
	DGantt tabla[tam];
	char *n="Vuelta>",*s="---------";
	int t=0, timecpu=0, m=0;
	do{		
		for(m=0;m<num_proc;m++){
			if(proc[m].tiempo == 0 && (i+1)==num_proc ){
				cn++;
			}
		}	
		//Se toma los valores iniciales como son declarados
		if(strcasecmp(proc[i].estado,"Inicializado")==0 ){
			strcpy(tabla[j].nombre,proc[i].nombre); 
			tabla[j].tiempo=proc[i].tiempo;
			strcpy(tabla[j].estado,proc[i].estado); 	
			tabla[j].gantt=timecpu;
		}

		//Si el proceso tiene un estado finalizado y tiempo en 0, se es ignorado y continua
	//	if(strcasecmp(proc[i].estado,"Finalizado")==0 && proc[i].tiempo==0){
	//		i++;
	//	}


		if(proc[i].tiempo<time_ejec && proc[i].tiempo != 0){
			timecpu=timecpu+proc[i].tiempo;
			time_act=0;
			SF="Finalizado";
			//Se hace el recorrido +1 en j la cual ayuda a llenar valores en el vector tabla
			j++;
			//Se actualiza el estado en el vector proc[i]
			strcpy(proc[i].estado,SF);
			proc[i].tiempo=time_act;
			//Se llena los datos del atributo para el vector tabla
			strcpy(tabla[j].nombre,proc[i].nombre); 
			tabla[j].tiempo=proc[i].tiempo;
			strcpy(tabla[j].estado,proc[i].estado); 
			//Se guarda el estado que se finalizo el proceso	
			tabla[j].gantt=timecpu;
		}else if(proc[i].tiempo>=time_ejec){
			//Optencion del tiempo restante del proceso
			time_act=proc[i].tiempo-time_ejec;
			//Si el tiempo restante es igual a cero se declara el estado finalizado
			if(time_act==0){
				//Se suma el tiempo en el cpu
				timecpu=timecpu+time_ejec;
				SF="Finalizado";
				j++;
				strcpy(proc[i].estado,SF);
				proc[i].tiempo=time_act;
				strcpy(tabla[j].nombre,proc[i].nombre); 
				tabla[j].tiempo=proc[i].tiempo;
				strcpy(tabla[j].estado,proc[i].estado); 
				tabla[j].gantt=timecpu;
			}
			else{
				SE="Ejecucion";
				//Se actualiza el el vector proc[i]
				proc[i].tiempo= time_act;
				strcpy(proc[i].estado,SE); 	
				//Se recorre una posicion para el vector tabla "Ejecucion"
				j++;
				//Se llena los datos del atributo para el vector tabla
				strcpy(tabla[j].nombre,proc[i].nombre); 
				tabla[j].tiempo=proc[i].tiempo;
				strcpy(tabla[j].estado,proc[i].estado); 	
				tabla[j].gantt=timecpu;

				//Se suma el tiempo en la cpu con el quantum 
				timecpu=timecpu+time_ejec;
				SB="Bloqueado";
				//Se actualiza el el vector proc[i]
				strcpy(proc[i].estado,SB);
				//Se recorre una posicion para el vector tabla "Bloqueado"
				j++;
				//Se llena los datos del atributo para el vector tabla
				strcpy(tabla[j].nombre,proc[i].nombre); 
				tabla[j].tiempo=proc[i].tiempo;
				strcpy(tabla[j].estado,proc[i].estado); 	
				tabla[j].gantt=timecpu;	
			}
		}	
		//Si i es igual al numero de procesos de coloca en 0 
		//para que el ciclo del vector se realice de nuevo
		if((i+1)==num_proc){
			i=0;
			//Posicion para llenar un vector de detalles
			j++;
			//Numero de vuelta=t
			t++;
			//Se llena un espacio en el vector tabla
			// para especidcar el numero de vuelta
			strcpy(tabla[j].nombre,n);
			tabla[j].tiempo=t;
			strcpy(tabla[j].estado,s);
			tabla[j].gantt=t;
		}else{
			i++;
		}

		if(cn==num_proc){
			bandera=1;
		}

	}while(bandera==0);	
//Tabla de estados de los procesos
	printf("\n\n\t\t HISTORAL DE PROCESOS\n");
	printf("Nombre del proceso|\tTiempo\t|\tEstado\t|\tTiempo en el CPU\n");
	//Se recorre el vector tabla para imprimir sus datos
	for(i=0;i<tam;i++){
		printf("\t%s\t", tabla[i].nombre);
		printf("\t%d\t", tabla[i].tiempo);
		printf("\t%s", tabla[i].estado);
		printf("\t%d\n", tabla[i].gantt);
	}	
//Tabla de procesos finalizado
	printf("\t\t TABLA DE PROCESOS RESULTADO\n");
	printf("Nombre del proceso |\tTiempo\t|\tEstado\t|\n");	
	for(i=0;i<num_proc;i++){
		printf("\t%s\t", proc[i].nombre);
		printf("\t%d\t", proc[i].tiempo);
		printf("\t%s\n", proc[i].estado);
	}
return 0;
}
