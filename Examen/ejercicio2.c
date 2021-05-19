#include <stdio.h>
int main(){
char arrayChar[5];
int bd=0;
char letra='a';
do{
	arrayChar[bd]=letra;
	letra++;
	bd++;
}while(letra<='e');
/*int i;
for(i=0;i<5;i++){
	printf("%c\n",arrayChar[i]);
}*/
char *punteroCharDos;
punteroCharDos=&arrayChar[0];
printf("%c\n",arrayChar[0]);
printf("\nEL contenido del puntero es: %c",*punteroCharDos);
printf("%c\n",arrayChar[5]);
return 0;
}
