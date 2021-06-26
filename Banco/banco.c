#include "banco.h"

void instrucciones(){
        printf("\n-------------------------------");
        printf("---- Menu ----\n");
        printf(" 0 Mostrar menu.\n");
        printf(" 1 Dar de alta Cliente.\n");
        printf(" 2 Dar de baja Cliente.\n");
        printf(" 3 Mostrar todos los clientes.\n");
        printf(" 4 Mostrar cliente en especifico.\n");
        printf(" 5 Mostrar solo clientes dados de alta.\n");
        printf(" 6 Abonar saldo a cliente.\n");
        printf(" 7 Retirar saldo de cliente.\n");
        printf(" 8 Buscar indice vacio en toda la estructura.\n");
        printf(" 9 Mostrar si esta toda llena la estructura.\n");
        printf(" 10 Mostrar si esta toda vacia la estructura.\n");
        printf(" 11 Mostrar nombre de paises.\n");
        printf(" 12 Mostrar longitudes.\n");
        printf(" 13 Actualizar datos de cliente especifico.\n");
        printf(" 14 Salir.\n");
        printf("-------------------------------");
}

void saltoLinea(){
        printf("\n");
}

int validarRango(int inicio, int fin, char *mensaje){
	printf("%s",mensaje);
	int numero;
	scanf("%d",&numero);
    while(numero < inicio || numero > fin){
        if(numero < inicio || numero > fin){
            printf("\t\tNo esta dentro del Rango...\n");
            printf("\t\t\t--> El rango va de %d a % d\n",inicio,fin);
        }
        puts(mensaje);
        scanf("%d",&numero);
    }
    return numero;
}

bool estaNombreRepetido(int tam_banco, char *nombrePais, Banco banco[]){
        bool se_encuentra;
        int i;
        for(i = 0; i < tam_banco ; i++){
        	//Se comparan las cadenas para saber si son las mismas
        	if(  strcasecmp(banco[i].nombrePais,nombrePais) == 0 ){ 
                	se_encuentra = true;    
                	break;            	
	        }else{
	        	se_encuentra = false;	        	                	
	        }
        }
  
        return se_encuentra;
}

char *nombrePaisR(int tam_banco, Banco banco[]){
	bool bandera;
	char nombrePais[20];
	char* cadena = malloc(20);
 	do{
		printf("\nIntroduce el nombre del País\t");
		memset(nombrePais,'\0',20);
		scanf("%s",nombrePais); 
		bandera=estaNombreRepetido(tam_banco, nombrePais, banco);
		if(bandera==true){
               	printf("\t\tEl nombre %s ya se encuentra registrado...\n",nombrePais);
                	printf("\t\t\t--> Intenta de nuevo.\n");
            	}            					
	}while(bandera==true);
	strcpy(cadena,nombrePais);	
	return cadena;
}
 
 char *nombrePais(int tam_banco, Banco banco[]){
	char nombrePais[20];
	char* cadena = malloc(20);
	bool bandera;
	do{
		printf("\nIntroduce el nombre del País\t");
		memset(nombrePais,'\0',20);
		scanf("%s",nombrePais); 
		bandera=estaNombreRepetido(tam_banco, nombrePais, banco);
		if(bandera==false){
               	printf("\t\tEl nombre %s no se encuentra registrado...\n",nombrePais);
                	printf("\t\t\t--> Intenta de nuevo.\n");
            	} 
	}while(bandera==false);	           					
	strcpy(cadena,nombrePais);	
	return cadena;
}	

void introducirPaises(Banco banco[], int tam_banco){
	int i,tam_cliente;
	for(i = 0; i < tam_banco; i++){
		strcpy(banco[i].nombrePais,nombrePaisR(tam_banco,banco));	
		tam_cliente=validarRango(1, LIMITE_CLIENTES, "\tIntroduce el total de clientes\t");
		banco[i].clientes[tam_cliente];	
		banco[i].num_clientes=tam_cliente;
    }
} 

void mostrarLongitudes(Banco banco[],int tam_banco){
	int i;
	for(i=0;i<tam_banco;i++){
		printf("--> Del Pais %s ------existen %d clientes.\n",banco[i].nombrePais,banco[i].num_clientes);
	}
	
}

bool getIsOcupadoCliente(Banco banco[],int indice_pais,int index){
        bool ocupado=false;
        if(banco[indice_pais].clientes[index].ocupado != true){
        	ocupado=false;
	}else{
		ocupado=true;
	}
	return ocupado;
} 

int getTotalClientes(Banco banco[], int posicion){
    return banco[posicion].num_clientes;
}


bool isTodoOcupado(Banco banco[], int indice_pais){
	bool todo_ocupado = false;
	int contador = 0,i;
	for(i = 0; i < getTotalClientes(banco, indice_pais) ; i++){
    		if(getIsOcupadoCliente(banco,indice_pais,i)){
            		contador++;
        	}
    	}
	if(contador == getTotalClientes(banco,indice_pais)){	
    		todo_ocupado = true;
    	}
    	return todo_ocupado;
}

bool hayVacioTodaEstructura(Banco banco[], int tam_banco){
	bool hayLugar = false;
	int i;
	for(i=0;i<tam_banco;i++){
		bool ocupado=isTodoOcupado(banco,i);
            if (ocupado==false) {
                hayLugar = true;
            }
        }
	return hayLugar;
}

int getIndicePais(char *nombrePais, Banco banco[], int tam_banco){
        int indexPais;
        int i;
        for(i = 0; i < tam_banco; i++){
        	if(strcasecmp(banco[i].nombrePais,nombrePais)){
        		indexPais = i;
        		break;
		}
        }
        return indexPais;
}

int indiceVacio(Banco banco[], int pais){
    int index_vacio=-1;
    int i;
    for(i = 0; i < getTotalClientes(banco,pais) ; i++){
        if(getIsOcupadoCliente(banco,pais,i)==false){ 
        	index_vacio = i;
        	break;
        }
    }
    return index_vacio;
}

int indiceVacioPaisEspecifico(int pais, Banco banco[]){
	int index_vacio=-1;
	index_vacio=indiceVacio(banco, pais);
        return index_vacio;
}
    
char *nombreCliente(){
	char nombreCliente[20];
	char* cadena = malloc(20);
	printf("\nIntroduce el nombre del cliente\t");
	memset(nombreCliente,'\0',20);
	scanf("%s",nombreCliente); 
	strcpy(cadena,nombreCliente);	
	return cadena;
}

void eliminarCliente(Banco banco[],int pais,int index){
	strcpy(banco[pais].clientes[index].nombre," ");
	banco[pais].clientes[index].sexo=' ';
	banco[pais].clientes[index].saldo=0.0;
	banco[pais].clientes[index].ocupado=false;
}

bool existeEspacioOcupado(Banco banco[], int pais){
    bool existeOcupado = false;
    int i;
    for(i = 0; i < getTotalClientes(banco, pais); i++){
            if(getIsOcupadoCliente(banco,pais,i)==true){
                existeOcupado = true;
                break;
            }
        }
    return existeOcupado;
}

bool estaTodoVacioEstructura(Banco banco[], int tam_banco){
        bool all_vacio = true;
        int i;
        for (i=0; i<tam_banco;i++) {
            if (existeEspacioOcupado(banco,i)==true) {
                all_vacio = false;
                break;
            }
        }
        return all_vacio;
}

void imprimirTodo(Banco banco[], int tam_banco){
	int i;
	for(i = 0; i < tam_banco; i++){
    	int j;
		for(j=0;j<getTotalClientes(banco, i);j++){			printf("----------------------------------------------------------------------------------------------------------------");
        	printf("\n\t---->Del pais %s",banco[i].nombrePais);
            printf("\n\t\tCliente[%i]",j);
            printf("\n\t\t\tNombre: %s",banco[i].clientes[j].nombre);
            printf("\n\t\t\tSexo: %c",banco[i].clientes[j].sexo);
            printf("\n\t\t\tSaldo: %lf",banco[i].clientes[j].saldo);
		}            
    }
    printf("----------------------------------------------------------------------------------------------------------------");
}

void imprimirEspecifico(Banco banco[],int pais,int cliente){
    printf("----------------------------------------------------------------------------------------------------------------");
    printf("\n\t---->Del pais %s: ",banco[pais].nombrePais);
    printf("\n\t\t\tNombre: %s",banco[pais].clientes[cliente].nombre);
    printf("\n\t\t\tSexo: %c",banco[pais].clientes[cliente].sexo);
    printf("\n\t\t\tSaldo: %lf",banco[pais].clientes[cliente].saldo);
    printf("----------------------------------------------------------------------------------------------------------------");
}

bool printSoloOcupados(Banco banco[],int pais){
    bool imprimio = false;
    if(existeEspacioOcupado(banco, pais)==true){
        imprimio = true;
        printf("----------------------------------------------------------------------------------------------------------------");
        printf("\tDel pais [%s] los clientes disponibles son:",banco[pais].nombrePais);
        int i;
        for(i = 0; i < getTotalClientes(banco,pais); i++){
                if(getIsOcupadoCliente(banco,pais,i)){
                    printf("El cliente %d es: ",i);
                    printf("\n\t\t\tNombre: %s",banco[pais].clientes[i].nombre);
    		    printf("\n\t\t\tSexo: %c",banco[pais].clientes[i].sexo);
    		    printf("\n\t\t\tSaldo: %lf",banco[pais].clientes[i].saldo);
                }
            }
            printf("----------------------------------------------------------------------------------------------------------------");
        }
        return imprimio;
}

void imprimirSoloOcupados(Banco banco[], int tam_banco){
        int contador = 0;
        int i;
        for(i = 0; i < tam_banco; i++){
            if(printSoloOcupados(banco,i))
                contador++;
        }
        if(contador == 0){
            printf("\t\t ---> No existen clientes que mostrar...");
        }
}

bool tieneDatos(Banco banco[], int pais, int indice){
	bool tiene_Datos=false;	
	if(strcasecmp(banco[pais].clientes[indice].nombre," ")==0 ||
		banco[pais].clientes[indice].sexo==' '){	
			tiene_Datos=false;
    }else{
    	tiene_Datos=true;    	 
	}
	return tiene_Datos;           
}

void abonarSaldo(Banco banco[], int pais, int indice ,double cuanto){
    if(tieneDatos(banco, pais,indice)==true) {
        if(cuanto > 0.0){
        	banco[pais].clientes[indice].saldo=banco[pais].clientes[indice].saldo+cuanto;
        }
        else{
            printf("\tImposible, no puedes abonar saldos negativos o nada.");
        }
    }
}

void abonarSaldoCliente(Banco banco[], int pais, int index, double cuanto){
		abonarSaldo(banco,pais,index,cuanto);
}

bool tieneSaldo(Banco banco[], int pais, int indice){
	bool tiene_Saldo=false;
	if(banco[pais].clientes[indice].saldo > 0.0){
		tiene_Saldo=true;
	}else{
		tiene_Saldo=false;
	}
        return tiene_Saldo;
}

void retirarSaldo(Banco banco[], int pais, int indice,double cuanto){
    if(tieneDatos(banco, pais,indice)==true) {
        if(cuanto > 0.0){
                if(tieneSaldo(banco, pais, indice)==true){
                    if(banco[pais].clientes[indice].saldo >= cuanto){
                        banco[pais].clientes[indice].saldo= banco[pais].clientes[indice].saldo-cuanto;
                    }else{					
                        printf("\tImposible, tú saldo es insuficiente para retirar %f",cuanto);
                	}
                }
                else{				
                    printf("\tImposible, no hay saldo.");
            	}
            }
        else{		
            printf("\tImposible, no puedes retirar saldos negativos o nada.");
        }
    }
}

void retirarSaldoCliente(Banco banco[], int pais, int index, double cuanto){
        retirarSaldo(banco, pais, index, cuanto);
}
						    
Indices indiceVacioTodaEstructura(Banco banco[],int tam_banco) {
	Indices temp;//new Indices();
	temp.pais=-1;
	temp.cliente=-1;
	int i;
	for(i = 0; i < tam_banco; i++) {
		int indice;
		indice = indiceVacio(banco, i);
		if(indice != -1) {
			temp.pais = i;
            temp.cliente = indice;
			break;            					
		}
	}
	return temp;
}

bool existeEspacioVacio(Banco banco[], int pais){
    bool existeVacio = false;
    int i;
    for(i = 0; i < banco[pais].num_clientes ; i++){
            if(getIsOcupadoCliente(banco,pais, i)==true){
                existeVacio = true; 
                break;
            }
        }
        return existeVacio;
    }

bool estaTodoLlenoEstructura(Banco banco[], int tam_banco){
    bool all_lleno = true;
    int i;
    for (i=0;i<tam_banco;i++) {
        if (existeEspacioVacio(banco,i)==true) {
                all_lleno = false;
                break;
            }
        }
        return all_lleno;
}

void imprimirPaises(Banco banco[], int tam_banco){
        printf("---------------------------------------------------------------------\n");
        printf("\tLos paises son: \n");
        int i;
        for(i = 0; i < tam_banco; i++){
            printf("\t---->País [%s] ",banco[i].nombrePais);
        }
        printf("---------------------------------------------------------------------\n");
}

void instrucciones_actualizar(){
        printf("\n-------------------------------");
        printf("---- Menú Actualizar ----\n");
        printf(" 0 Mostrar menú.\n");
        printf(" 1 Actualizar Nombre.\n");
        printf(" 2 Actualizar Sexo.\n");
        printf(" 3 Regresar a ménu principal.\n");
        printf("-------------------------------");
}

void setTodosDatos(Banco banco[],int pais, int indice){	
    strcpy(banco[pais].clientes[indice].nombre, " ");
    banco[pais].clientes[indice].sexo = ' ';
    banco[pais].clientes[indice].saldo = 0.0;
    banco[pais].clientes[indice].ocupado = false;
}

void setOcupado(Banco banco[], int pais, int indice) {
    if(tieneDatos(banco, pais,indice)==false){
        setTodosDatos(banco, pais, indice);
    }
    else{
        banco[pais].clientes[indice].ocupado = true;
    }
}

void cambiarNombre(Banco banco[], int pais, int indice, char nuevoNombre[20]){
	/*Si primer cadena > a segunda resultado es mayor a 0
		Si primer cadena > a segunda resultado es menor a 0
			Si cadenas iguales resultado 0*/
	if(strcasecmp(nuevoNombre," ")>0){	        
            strcpy(banco[pais].clientes[indice].nombre,nuevoNombre);
        }
    setOcupado(banco, pais, indice);
}

void cambiarNombreCliente(Banco banco[], int pais, int index, char nuevoNombre[20]){
        cambiarNombre(banco,pais, index,nuevoNombre);
}

void printCliente(Banco banco[], int pais,int index){
    printf("-->Nombre: %s\n",banco[pais].clientes[index].nombre);
    printf("-->Sexo: %c\n",banco[pais].clientes[index].sexo);
    printf("-->Saldo: %f\n",banco[pais].clientes[index].saldo);
}

void cambiarSexo(Banco banco[], int pais, int indice, char sexo){
    if(sexo == 'M' || sexo == 'F'){
        banco[pais].clientes[indice].sexo = sexo;
    }
    setOcupado(banco, pais, indice);
}

void cambiarSexoCliente(Banco banco[], int pais, int index, char nuevoSexo){
    cambiarSexo(banco, pais, index, nuevoSexo);
}


