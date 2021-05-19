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

char *punteroChar;
punteroChar=&arrayChar[0];
	
char *punteroCharDos;
punteroCharDos=&arrayChar[0];

printf("\nArray primer valor: %c",arrayChar[0]);
printf("\nPrimer elemento del punteroChar: %c",*punteroChar);
printf("\nPrimer elemento del pubteroCharDos: %c",*punteroCharDos);	
printf("\nQuinto elemento del array: %c",arrayChar[4]);	
printf("\nQuinto elemento del punteroChar: %c",*(punteroChar+4));
printf("\nQuinto elemento del punteroCharDos: %c",*(punteroCharDos+4));
int i;
printf("\n11.-PunteroCharDos ");
for (i = 0; i < 5; ++i){
	printf("\nLetra: %c", *(punteroCharDos+i));
}
printf("\n12.-PunteroCharDos ");
for (i = 0; i < 5; ++i){
	printf("\nLetra: %c", *(punteroCharDos+i)); 
}
/*printf("\n-PunteroChar ");
for (i = 0; i < 5; ++i){
	printf("\nLetra: %c", *(punteroChar+i)); 
}*/

return 0;
}
