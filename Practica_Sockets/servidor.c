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
	//Estructuras de tipo sockaddr para guardar la informacion 
	int sockfd;
	struct sockaddr_in serverAddr;
	
	int newSocket;
	struct sockaddr_in newAddr;
	
	socklen_t addr_size;
	char buffer[MAX_DATA];
	char *buf;

	//Definir socket
	/*SI el resultado es -1 hubo un error*/
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		printf("[**]NO se puedo crear el servidor[**]\n");
		exit (-1);
	}else{
		printf("[**]SERVIDOR CREADO EXITOSAMENTE[**]\n");
		
		memset(&serverAddr,'\0',sizeof(serverAddr));
		//Configuracion del servidor 
		serverAddr.sin_family=AF_INET;//Familia tcp/ip
		serverAddr.sin_port=htons(PORT); //Puerto 
		serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");//DIreccion en especifico
		/*Se puede moficar para que cualquiera pudiera conectar cambiando la direccion por: INADDR_ANY*/
	
		//Avisar al sistema que se creo un socket
		/*SI el resultado es -1 hubo un error*/
		if(bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
			printf("[++]Error en el bind[++]\n");
			printf("++Intente más tarde++\n");
			exit (-1);
		}else{
			printf("[++]Numero de puerto %d[++]\n",4455);
			
			//Poner el socket en modo escucha 
			/*SI el resultado es -1 hubo un error*/
			if(listen(sockfd,5)<0){
				printf("[//]Error en el listen[\\]");
				exit (-1);
			}else{
				printf("[//]Listen[\\]\n");
				
				addr_size=sizeof(newAddr);
				//Aceptar conexion
				newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
				strcpy(buffer,"HOLA, servidor disponible\n");
				//SE envia al cliente la cadena 
				send(newSocket,buffer,strlen(buffer),0);
				printf("[~~]Enviando informacion al cliente[~~]\n");
	
				//Primer valor
				printf("[~~]Recibiendo valores[~~]\n");
				//LImpiar buffer
				memset(&buffer,'\0',sizeof(buffer));
				recv(newSocket,buffer,MAX_DATA,0);
				printf("[^^]INF. RECIVIDA[^^]: %s \n",buffer);
				//Tamaño de numeros
				unsigned long int numbytes=strlen(buffer);
				printf ("Bytes:%lu\n",numbytes);
				//Convertir cadena a entero
				//unsigned long int valor1=atoi(buffer);
				unsigned long  int valor1=strtoul(buffer, &buf, 0);
				printf("Numero en entero %lu\n",valor1);
				if(strlen(buf)>=1){
					printf("ERROR ~~Ingreso caracteres~~\n");
					printf("%s\n",buf);
				}
	
				//SE envia al cliente la cadena 
				memset(&buffer,'\0',sizeof(buffer));
				strcpy(buffer,"Envie el segundo valor\n");
				send(newSocket,buffer,strlen(buffer),0);
				printf("[~~]Enviando informacion al cliente[~~]\n");	

				//Segundo valor
				//LImpiar buffer
				memset(&buffer,'\0',sizeof(buffer));
				recv(newSocket,buffer,MAX_DATA,0);
				printf("[^^]INF. RECIVIDA[^^]: %s \n",buffer);
				//Tamaño de numeros
				numbytes=strlen(buffer);
				printf ("Bytes:%lu\n",numbytes);
				//Convertir cadena a entero
				//unsigned long long int valor2=atoi(buffer);
				unsigned long int valor2=strtoul(buffer, &buf, 0);
				printf("Numero en entero %lu\n",valor2);
				if(strlen(buf)>=1){
					printf("ERROR ~~Ingreso caracteres~~\n");
					printf("%s\n",buf);
				}
	

				memset(&buffer,'\0',sizeof(buffer));
				unsigned long int suma=valor1+valor2;
				/*itoa no funcina en Ubuntu*/
				//itoa(suma,buffer,10);
				sprintf(buffer, "%lu",suma);
	
				//SE envia al cliente la cadena 
				send(newSocket,buffer,strlen(buffer),0);
				printf("[~~]Enviando informacion al cliente[~~]\n");
		
			}
	
	
		}
	
	
	}
	
	
	
	

}






