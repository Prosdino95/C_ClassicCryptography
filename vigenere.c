#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define alf 26 //lunghezza alfabeto

void carica_tavola(unsigned char tavola[alf][alf]){
	int i,j,n;
	char prima[alf]="abcdefghijklmnopqrstuvwxyz";
	for(i=0;i<alf;i++)
		for(j=0;j<alf;j++){
		tavola[i][j]=prima[j]+i;
		if(tavola[i][j]>'z') tavola[i][j]-='z'-'a'+1;
		}
}

void stampa(unsigned char tavola[alf][alf]){
	int i,j;
	for(i=0;i<alf;i++){
		if(i<10)printf("%d  ",i);
		else printf("%d ",i);//formattare la visualizzazione della tavola
		for(j=0;j<alf;j++){
		printf("%c ",tavola[i][j]);
		}
		printf("\n");
	}
}

char *cripta(char *frase,unsigned char tavola[alf][alf],char *chiave){
		int i,j;
		int k=0;
		int h=0;
		int n=0;
		int lun=strlen(frase);
		int lunc=strlen(chiave);
		for (i=0;i<lun;i++){
			for(j=0;j<alf;j++)
				if (tavola[j][0]==chiave[k]){
					for(h=0;h<alf;h++)
						if(tavola[0][h]==frase[i]){
							frase[i]=tavola[j][h];
							k++;
							h=alf; //dato che la frase[i] cambia forzo l'uscita dal ciclo per evitare che 
						           //venga eseguito di nuovo if con la lettera criptata
						} 
					j=alf;	 //esco anche da j per non compiere operazioni inutili (non potevo usare break)
					}						
		if(k==lunc) k=0;	
		}																
		return frase;
}


int main(){
	unsigned char tavola[alf][alf];
	char frase[]="aaaaaaaaaaaa";
	char chiave[alf];
	carica_tavola(tavola);
	stampa(tavola);
	printf("inserire parola chiave: ");
	scanf("%s",chiave);
	cripta(frase,tavola,chiave);
	printf("frase criptata: %s \n",frase);

return 0;
}