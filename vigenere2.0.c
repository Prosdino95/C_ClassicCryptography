#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define alf 26 //lunghezza alfabeto
char alfabeto[alf]="abcdefghijklmnopqrstuvwxyz";

char *cripta(unsigned char *frase,char *chiave){
		int i,j,n,h=0;
		int lun=strlen(frase);
		int lunc=strlen(chiave);
		for (i=0;i<lun;i++){
			for(j=0;j<alf;j++)
				if(chiave[h]==alfabeto[j]){
					n=j;
				}
			frase[i]=frase[i]+n;
			h++;
			if(h==lunc) h=0;	
		}																		
		return frase;
}


void main(){
	unsigned char frase[]="aaaaaaaaaaaa";
	char chiave[]="ciao";
	cripta(frase,chiave);
	printf("frase criptata: %s \n",frase);
}