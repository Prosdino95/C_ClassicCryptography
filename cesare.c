#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
int n=0;
int conta=0;
sem_t sem;
pthread_t th1;
pthread_t th2;
pthread_t th3;
pthread_t th4;
pthread_t th5;


int *char_to_int(unsigned char *str,int l,int *vett){
	int i=0;
	for(i=0;i<l;i++){
	vett[i]=(int)str[i];
	}
	return vett;				
}

void step(int *vett,int n,int l){
	int i=0;
	for(i=0;i<l;i++){
		vett[i]=vett[i]+n;
// 122="z" , 97="a" 26=122-97		
		if(vett[i]>122)
			vett[i]=vett[i]-26;
	}
}

void stampa(unsigned char* str){
	printf("Tentativo di decifrare %s \n ",str);
}

void int_to_char(int *vett,unsigned char* str,int l){
	int i=0;
	unsigned char s[l];
	for(i=0;i<l;i++){
		s[i]=(unsigned char)vett[i];
		
	}
	stampa(s);
}



void *cesare(void *str){
	int i=0;
	int lunghezza=(strlen(str));
	int vett[lunghezza-1];
	int* temp;
	unsigned char* temp2;
			temp=char_to_int(str,lunghezza,vett);
			conta++;	
	if(conta==5)sem_post(&sem);
	sem_wait(&sem);	
			n++;
			step(temp,n,lunghezza);
	sem_post(&sem);		
		int_to_char(temp,str,lunghezza);
}



int main(){	
	int j=0;
	//ciaocomevasperobeneiotuttobene
	unsigned char stringa[]="Fabrgal";
	sem_init(&sem,0,0);
	printf("\n");
	printf("originale: %s\n",stringa);
	for(j=0;j<5;j++){
	pthread_create(&th1,NULL,&cesare,(void*)stringa);
	pthread_create(&th2,NULL,&cesare,(void*)stringa);
	pthread_create(&th3,NULL,&cesare,(void*)stringa);
	pthread_create(&th4,NULL,&cesare,(void*)stringa);
	pthread_create(&th5,NULL,&cesare,(void*)stringa);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);
	pthread_join(th5,NULL);
	conta=0;
}
	return 0;
}
