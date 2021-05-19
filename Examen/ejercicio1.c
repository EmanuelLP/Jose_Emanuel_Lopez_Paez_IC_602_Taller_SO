#include <stdio.h>

int  main(){
char x;
char *p;
char y;
char *puntero;
x='x';
p=&x;
//printf("\nDireccion de memoria: %p",&x);
printf("\nEL contenido del puntero p es: %c",*p);
p++;
printf("\nEL contenido del puntero p+1 es: %c",*p);
p+=2;
printf("\nEL contenido del puntero p+2 es: %c",*p);
y='y';
puntero=&y;
printf("\nEL contenido del puntero puntero es: %c\n",*puntero);
return 0;
}
