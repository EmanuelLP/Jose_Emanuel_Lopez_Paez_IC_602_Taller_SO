#include <stdio.h>
#include <string.h>
// Debe ser de la máxima + 1. Por ejemplo, si la máxima es 4, defínela como 5
#define MAXIMA_LONGITUD_CADENA 1000

// Implementación del método de la burbuja en C, para arreglos de cadenas
void burbuja(char arreglo[][MAXIMA_LONGITUD_CADENA], int longitud)
{
    // Útil para hacer intercambio de cadenas
    char temporal[MAXIMA_LONGITUD_CADENA];
    int x, indiceActual;
    for (x = 0; x < longitud; x++)
    {
        for (indiceActual = 0; indiceActual < longitud - 1;
             indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            // Si la cadena es mayor que la siguiente (alfabeticamente) entonces intercambiamos
            if (strcmp(arreglo[indiceActual], arreglo[indiceSiguienteElemento]) > 0)
            {
                // Movemos la cadena actual a la temporal
                memcpy(temporal, arreglo[indiceActual], MAXIMA_LONGITUD_CADENA);
                // Movemos al actual el siguiente elemento
                memcpy(arreglo[indiceActual], arreglo[indiceSiguienteElemento], MAXIMA_LONGITUD_CADENA);
                // Y en el siguiente elemento, lo que había antes en el actual pero ahora está en temporal
                memcpy(arreglo[indiceSiguienteElemento], temporal, MAXIMA_LONGITUD_CADENA);
            }
        }
    }
    // No hay necesidad de devolver nada, pues modificamos al arreglo de manera interna
}



int main()
{
    char palabras[][MAXIMA_LONGITUD_CADENA] = {
        "aaria",
        "Luis",
        "Bojack",
        "Leon",
        "Maggie",
        "link",
        "Mario",
        "Claire",
        "Zanahoria",
        "Baroness Von Bon Bon",
    };
    int longitud = sizeof(palabras) / sizeof(palabras[0]);
    // Imprimimos el arreglo antes de ordenarlo, solo para ilustrar
    printf("---Imprimiendo arreglo sin ordenar---\n");
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf("%s\n", palabras[i]);
    }
    // Lo ordenamos
    burbuja(palabras, longitud);
    // Volvemos a imprimir
    printf("---Imprimiendo arreglo ordenado---\n");
    for (i = 0; i < longitud; i++)
    {
        printf("%s\n", palabras[i]);
    }
    return 0;
}
