#ifndef __banco
#define __banco

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <malloc.h>

#define MOSTRAR_MENU_PRIN 0
#define LIMITE_PAISES	5
#define LIMITE_CLIENTES 10
#define ALTA 1
#define BAJA 2
#define MOSTRAR_TODO 3
#define MOSTRAR_ESPECIFICO 4
#define MOSTRAR_OCUPADOS 5
#define ABONAR 6
#define RETIRAR 7
#define BUSCAR_ID_VACIO_ESTRUCTURA 8
#define ESTA_LLENA_ESTRUCTURA 9
#define ESTA_VACIA_ESTRUCTURA 10
#define IMPRIMIR_NOM_PAISES 11
#define MOSTRAR_LONGITUDES 12
#define ACTUALIZAR 13
#define SALIR 14
#define ACTUALIZAR_MOSTRAR_MENU 0
#define ACTUALIZAR_NOMBRE 1
#define ACTUALIZAR_SEXO 2
#define SALIR_ACTUALIZAR 3


typedef struct {
	char nombre[20];
	char sexo;
	double saldo;
	bool ocupado;
}Cliente;

typedef struct {
	char nombrePais[20];
	int num_clientes;
	Cliente clientes[];
}Banco;

typedef struct {
	int pais;
	int cliente;
}Indices;

void instrucciones();

void saltoLinea();

int validarRango(int inicio, int fin, char *mensaje);

bool estaNombreRepetido(int tam_banco, char *nombrePais, Banco banco[]);

char *nombrePaisR(int tam_banco, Banco banco[]);
 
char *nombrePais(int tam_banco, Banco banco[]);	

void introducirPaises(Banco banco[], int tam_banco);

void mostrarLongitudes(Banco banco[],int tam_banco);

bool getIsOcupadoCliente(Banco banco[],int indice_pais,int index);

int getTotalClientes(Banco banco[], int posicion);

bool isTodoOcupado(Banco banco[], int indice_pais);

bool hayVacioTodaEstructura(Banco banco[], int tam_banco);

int getIndicePais(char *nombrePais, Banco banco[], int tam_banco);

int indiceVacio(Banco banco[], int pais);

int indiceVacioPaisEspecifico(int pais, Banco banco[]);
    
char *nombreCliente();

void eliminarCliente(Banco banco[],int pais,int index);

bool existeEspacioOcupado(Banco banco[], int pais);

bool estaTodoVacioEstructura(Banco banco[], int tam_banco);

void imprimirTodo(Banco banco[], int tam_banco);

void imprimirEspecifico(Banco banco[],int pais,int cliente);

bool printSoloOcupados(Banco banco[],int pais);

void imprimirSoloOcupados(Banco banco[], int tam_banco);

bool tieneDatos(Banco banco[], int pais, int indice);

void abonarSaldo(Banco banco[], int pais, int indice ,double cuanto);

void abonarSaldoCliente(Banco banco[], int pais, int index, double cuanto);

bool tieneSaldo(Banco banco[], int pais, int indice);

void retirarSaldo(Banco banco[], int pais, int indice,double cuanto);

void retirarSaldoCliente(Banco banco[], int pais, int index, double cuanto);
						    
Indices indiceVacioTodaEstructura(Banco banco[],int tam_banco);

bool existeEspacioVacio(Banco banco[], int pais);

bool estaTodoLlenoEstructura(Banco banco[], int tam_banco);

void imprimirPaises(Banco banco[], int tam_banco);

void instrucciones_actualizar();

void setTodosDatos(Banco banco[],int pais, int indice);

void setOcupado(Banco banco[], int pais, int indice);

void cambiarNombre(Banco banco[], int pais, int indice, char nuevoNombre[20]);

void cambiarNombreCliente(Banco banco[], int pais, int index, char nuevoNombre[20]);

void printCliente(Banco banco[], int pais,int index);

void cambiarSexo(Banco banco[], int pais, int indice, char sexo);

void cambiarSexoCliente(Banco banco[], int pais, int index, char nuevoSexo);

#endif
