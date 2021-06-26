#include "banco.h"

int main(){
	int eleccion;
	int tam_banco;
	tam_banco=validarRango(1,LIMITE_PAISES,"Introduce el número de paises: ");
	Banco banco[tam_banco];
	introducirPaises(banco, tam_banco);
	mostrarLongitudes(banco,tam_banco);
	saltoLinea();
	instrucciones();
	printf("\n Elija una opcion: ");
	scanf("%d",&eleccion);	
	while(eleccion != SALIR){
		switch(eleccion){
                case ALTA:
                	printf(" --- Opcion alta ---\n");                    
                    	if(hayVacioTodaEstructura(banco,tam_banco)==true){
                        	char nombre_pais[20];                        
                        	//PEDIRNOMBREPAIS
                        	strcpy(nombre_pais,nombrePais(tam_banco,banco));              
                        	//Obtener indice 
				int id_pais = getIndicePais(nombre_pais, banco, tam_banco);
				//Obtener indice cliente vacio
				int cliente= indiceVacioPaisEspecifico(id_pais, banco);
                        	if(cliente != -1){
	                        	char nombre_cliente[20];
    	                    		char sexo;
        	                	double saldo;
            	            		strcpy(nombre_cliente,nombreCliente());                  	    	
                        		printf("\nIntroduce el Sexo: ");
                        		scanf("%s",&sexo);
                        		printf("\nIntroduce el Sueldo: ");
                        		scanf("%lf",&saldo);                        		
		                    	//llenar datos
		                    	strcpy(banco[id_pais].clientes[cliente].nombre,nombre_cliente);
		                    	banco[id_pais].clientes[cliente].sexo=sexo;
		                    	banco[id_pais].clientes[cliente].saldo=saldo;
		                    	banco[id_pais].clientes[cliente].ocupado=true;
                        	}else{
                            		printf("No existe indice vacio en el pais %s",banco[id_pais].nombrePais);
                            	     }
                    	}else {
                        	printf("---------------------------------------------------------------------\n");
                        	printf("\t\t La estructura esta completamente llena.\n");
                        	printf("---------------------------------------------------------------------\n");
                    	}                
                break;
                case BAJA:
                    printf(" --- Opción baja ---\n");                    
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){
                        char nombre_pais[20];					
			//PEDIRNOMBREPAIS                       						
			strcpy(nombre_pais,nombrePais(tam_banco,banco)); 						
			//Obtener indice 
			int pais = getIndicePais(nombre_pais, banco, tam_banco);
                       //Obtener indice cliente
			int cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            printf("\t--> Cliente %s  dado de baja.",banco[pais].clientes[cliente].nombre);
                            eliminarCliente(banco,pais,cliente);
                        }else{
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                        }                       
                    }else{
                       printf("---------------------------------------------------------------------\n");
                       printf("\t\t La estructura esta toda vacia.\n");
                       printf("---------------------------------------------------------------------\n");
                    }
                break;
                case MOSTRAR_TODO:
                    printf(" --- Opción mostrar todo ---\n");
                    imprimirTodo(banco,tam_banco);
                break;
                case MOSTRAR_ESPECIFICO:
                    printf(" --- Opción mostrar especifico ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                        char nombre_pais[20];                        
                        //PEDIRNOMBREPAIS
                        strcpy(nombre_pais,nombrePais(tam_banco,banco));
                        int pais= getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            imprimirEspecifico(banco,pais,cliente);
                        }else{
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                        }
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case MOSTRAR_OCUPADOS:
                    printf(" --- Opción mostrar solo ocupados ---\n");
                    imprimirSoloOcupados(banco, tam_banco);
                break;
                case ABONAR:
                    printf(" --- Opción abonar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                   
                        char nombre_pais[20];                        
                        //PEDIRNOMBREPAIS
                        strcpy(nombre_pais,nombrePais(tam_banco,banco));				
                        int pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            double cuanto;
                            printf("\tIntroduce cuanto ingresarás a tú cuenta:  ");
			     scanf("%lf",&cuanto);
                            abonarSaldoCliente(banco, pais,cliente, cuanto);
                        }else{
                        	printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
			 }                                
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break; 
                case RETIRAR:
                    printf(" --- Opción retirar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                        char nombre_pais[20];                        
                        //PEDIRNOMBREPAIS
                        strcpy(nombre_pais,nombrePais(tam_banco,banco));				
                        int pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
 		         	double cuanto;
				printf("\tIntroduce cuanto retirarás de tú cuenta: ");
				scanf("%lf",&cuanto); 
                           	retirarSaldoCliente(banco, pais, cliente, cuanto);
                        }else{
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                        }
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case BUSCAR_ID_VACIO_ESTRUCTURA:
                    printf(" --- Opción buscar id vacio en toda estructura ---\n");
                    if(hayVacioTodaEstructura(banco, tam_banco)==true){
		     	Indices temp;
		  	temp = indiceVacioTodaEstructura(banco, tam_banco);
                       printf("---------------------------------------------------------------------\n");
                       printf("\tEl pais [%d] %s tiene el cliente [%d] vacio\n",temp.pais, banco[temp.pais].nombrePais, temp.cliente);
                       printf("---------------------------------------------------------------------\n");
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta completamente llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case ESTA_LLENA_ESTRUCTURA:
                    printf(" --- Opción esta llena toda la estructura ---\n");
                    if(estaTodoLlenoEstructura(banco, tam_banco)==true) {
                        printf("---------------------------------------------------------------------\n");
                        printf("\ttrue, la estructura esta toda llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\tfalse, la estructura no esta toda llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case ESTA_VACIA_ESTRUCTURA:
                    printf(" --- Opción esta vacia toda la estructura ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){
                        printf("---------------------------------------------------------------------\n");
                        printf("\ttrue, la estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\tfalse, la estructura no esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case IMPRIMIR_NOM_PAISES:
                    printf(" --- Opción imprimir nombre de paises ---\n");
                    imprimirPaises(banco, tam_banco);
                break;
                case ACTUALIZAR:
                    printf(" --- Opción actualizar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                    	char nombre_pais[20];                        
                        //PEDIRNOMBREPAIS
                        strcpy(nombre_pais,nombrePais(tam_banco,banco));						
                        int pais = getIndicePais(nombre_pais, banco, tam_banco);                        
                        int cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
			  if(getIsOcupadoCliente(banco,pais,cliente)==true){                                                  
                         	instrucciones_actualizar();
                         	printf(" Elija una opción: ");
                         	scanf("%d",&eleccion);                            
                         	while(eleccion != SALIR_ACTUALIZAR) {
                               	switch (eleccion) {
                                    		case ACTUALIZAR_NOMBRE:
                                        	printf(" --- Opción actualizar nombre ---\n");                                        
                                        	char nuevoNombre[20];
	            	            		strcpy(nuevoNombre,nombreCliente());					
                                        	cambiarNombreCliente(banco,pais,cliente,nuevoNombre);
                                        	printf("-----------------------------------------------------------------\n");
                                        	printCliente(banco, pais,cliente);
                                        	printf("-----------------------------------------------------------------\n");
                  			break;
                  			case ACTUALIZAR_SEXO:
                                       	printf(" --- Opción actualizar sexo ---\n");
                                       	char nuevoSexo;                                        
                                       	printf("Introduce el nuevo Sexo: ");
                                       	fflush(stdin);
						scanf("%s",&nuevoSexo);
						cambiarSexoCliente(banco,pais,cliente,nuevoSexo);
 	                                       printf("-----------------------------------------------------------------\n");
                                        	printCliente(banco, pais,cliente);
                                        	printf("-----------------------------------------------------------------\n");
                                       break;
                                    	case ACTUALIZAR_MOSTRAR_MENU:
                                        	instrucciones_actualizar();
                                       break;
                                    	default:
                                       	printf("******************************************\n");
                                       	printf(" --- Opción Desconocida ---\n");
                                       	printf("******************************************\n");                                   
                                        	instrucciones_actualizar();
                                }
                                printf(" Elija una opción: ");
                                scanf("%d",&eleccion);                                
                            }
                            instrucciones();
                        }else{
                        	printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
			}                            
                    }else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case MOSTRAR_LONGITUDES:
                    printf(" --- Opción mostrar longitudes ---\n");
                    printf("---------------------------------------------------------------------\n");
                    mostrarLongitudes(banco,tam_banco);
                    printf("---------------------------------------------------------------------\n");
                break;		
		case MOSTRAR_MENU_PRIN:
                    instrucciones();
                break;
		default:
                    printf("******************************************\n");
                    printf(" --- Opción Desconocida ---\n");
                    printf("******************************************\n");                    
                    instrucciones();				                 
            }
        instrucciones();
        printf(" Elija una opción: ");
        scanf("%d",&eleccion);    
    }
    printf("--- Fin de la Ejecución del Sistema ---\n");	
return 0;
}

