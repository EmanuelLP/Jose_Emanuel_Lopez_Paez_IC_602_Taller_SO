#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455
#define MAX_DATA 1024

void main(){
	int clientSocket;
	//Estrcutura para guardar informacion sel servidor remoto
	struct sockaddr_in serverAddr;
	char buffer[MAX_DATA];
	
	//Creacion del socket
	/*SI el resultado es -1 hubo un error*/
	clientSocket=socket(PF_INET, SOCK_STREAM, 0);
	if(clientSocket<0){
		printf ("[**]No puedo establecer conexion con el servidor[**]\n");
		exit (-1);
	}else{
	
		printf("[**]CLIENTE CREADO EXITOSAMENTE[**]\n");
		memset(&serverAddr,'\0',sizeof(serverAddr));	
		//Datos del servidor
		serverAddr.sin_family=AF_INET;//Familia tcp/ip
		serverAddr.sin_port=htons(PORT);//Puerto 	
		serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");//Direccion en especifico
	
		//Conectarse al servidor
		/*SI el resultado es -1 hubo un error*/
		if(connect(clientSocket, (struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
			printf("[++]Conexion fallida[++]\n");
			exit (-1);
		}
		else{
			printf("[++]Coneccion a servidor[++]\n");
			memset(&buffer,'\0',sizeof(buffer));
	
			//Revibir datos del servidor
			recv(clientSocket,buffer,MAX_DATA,0);
			printf("[^^]INF. RECIVIDA[^^]: %s \n",buffer);
	
			//Pedir primer valor
			char valor1[MAX_DATA];
			printf("Ingrese el primer valor de  (1-19 digitos)\n");
			scanf("%s",valor1);
			//Enviando valor1
			//strcpy(valor1,"1111111111111111111");
			send(clientSocket,valor1,strlen(valor1),0);
			printf("[~~]Valor 1 enviado[~~]\n");
	
			memset(&buffer,'\0',sizeof(buffer));
			//Recibir datos del servidor
			recv(clientSocket,buffer,MAX_DATA,0);
			printf("[^^]INF. RECIVIDA[^^]: %s \n",buffer);
	
			//Pedir segundo valor
			char valor2[MAX_DATA];	
			printf("Ingrese el segundo valor de  (1-19 digitos)\n");
			scanf("%s",valor2);
			//Enviando valor2
			//strcpy(valor2,"2222222222222222222");
			send(clientSocket,valor2,strlen(valor2),0);
			printf("[~~]Valor 2 enviado[~~]\n");
	
			memset(&buffer,'\0',sizeof(buffer));
			//Recibir datos del servidor
			recv(clientSocket,buffer,MAX_DATA,0);
			printf("[^^]Suma[^^]: %s \n",buffer);

	
			printf("[##]Cerrando conexion[##]\n");
		
		}
	
	
	
	
	
	}
	
	

	
}

