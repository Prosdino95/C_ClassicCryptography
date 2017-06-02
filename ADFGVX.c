#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define tab 7
#define alf 36

 char tavola[tab][tab]={	
	{' ','A','D','F','G','V','X'},
	{'A',' ',' ',' ',' ',' ',' '},
	{'D',' ',' ',' ',' ',' ',' '},
	{'F',' ',' ',' ',' ',' ',' '},
	{'G',' ',' ',' ',' ',' ',' '},
	{'V',' ',' ',' ',' ',' ',' '},
	{'X',' ',' ',' ',' ',' ',' '},
};


void stampa( char tavola[tab][tab]){
	int i,j;
	for(i=0;i<tab;i++){
		for(j=0;j<tab;j++){
		printf("%c ",tavola[i][j]);
		}
		printf("\n");
	}
}

void stampa_frase(char *str){
 int i;
 int l=strlen(str);
 for(i=0;i<l;i+=2){
 	printf("  %c%c  ",str[i],str[i+1]);
 }
}

int *azzera(int *vett){
	int i;
	for(i=0;i<alf;i++)
		vett[i]=-1;
	return vett;
}
//crea la tabella casuale
void carica_tavola( char tavola[tab][tab]){
	int i,j;
	int n=0;
	int vett[alf];
	int control=0;
	int t=0;
	char alfabeto[]="0123456789abcdefghijklmnopqrstuvwxyz";
	azzera(vett);
	while(t==0){
	n=rand()%alf;
	for(i=0;i<alf;i++)
		if(vett[i]==n)control=1;
	for(j=0;j<alf;j++){
		if(control==0 && vett[j]==-1){	vett[j]=n;
										break;
									}
	if(vett[alf-1]!=-1) t=1;
		}	
	control=0;				
 }
j=0;
for(i=1;i<tab;i++)
	for(t=1;t<tab;t++){
			n=vett[j];
			tavola[i][t]=alfabeto[n];
			j++;
			}
printf("tavola usata generata casualmete: \n");			
stampa(tavola);
}

int min(unsigned char *str){
	int i,min=0;
	int l=strlen(str);
	for(i=0;i<l;i++)
			if(str[i]<str[min])
				min=i;	
	str[min]='z'+1;		
	return min;		
}

 char *step_1( char tavola[tab][tab],char *frase){
	int l=strlen(frase);
	int i,j,h;
	int k=0;
	char *str;
	str=(char*)malloc(l*2*sizeof(char));
	for(i=0;i<l;i++)
		for(j=1;j<tab;j++)
			for(h=1;h<tab;h++)
				if(frase[i]==tavola[j][h]){
					str[k]=tavola[0][j];
					str[k+1]=tavola[h][0];
					k+=2;
				}
	return str;			
}


char *step_2(unsigned char *chiave,char *frase_cifrata){
	int l=strlen(frase_cifrata);
	int lc=strlen(chiave);
	int n,i,j=0,k;
	char *str;
	str=(char*)malloc(l*sizeof(char));
	for(i=0;i<lc;i++){
		n=min(chiave);	
		k=n;
		while(k<l){
			str[j]=frase_cifrata[k];
			k=k+lc;
			j++;
    	}
    k=0;	
	}
	return str;
}

void cripta(char tavola[tab][tab],char *frase,unsigned char *chiave){
	char *frase_cifrata;
	char scelta;
	printf("vedere passaggi intermedi? s/n \n");
	scanf("%s",&scelta);
	printf("\nTesto in chiaro chiaro: %s \n",frase);
	if(scelta=='s') printf("\nchiave: %s ",chiave);
	frase_cifrata=step_1(tavola,frase);
	if(scelta=='s'){ 
		printf("\n\nfrase criptata 1: \n");
		stampa_frase(frase_cifrata);
	}	
	frase_cifrata=step_2(chiave,frase_cifrata);
	printf("\n\nfrase criptata 2:\n%s \n",frase_cifrata);
	printf("\n");
}

void main(){
	int s;
	srand(time(NULL));
	char frase[]="abcdefg";
	char chiave[]="dbca";
	carica_tavola(tavola);
	cripta(tavola,frase,chiave);
}