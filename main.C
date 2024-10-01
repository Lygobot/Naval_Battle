#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define N 10 /* N deve essere pari, in questo caso ho una tabella 10x10 */ 

/* 2 navi da 1, 2 navi da 2, 1 nave da 3, 1 nave da 4, 1 nave da 5 , totale 7 barche*/
/* A=acqua/~, B=barca */

typedef struct {
	int colpito;
	int pezzo_barca;
	int lunghezza_barca;
	int attaccata;
}cella;

void inizializza_tab(cella m[][N]);
void genera_tab(cella m[][N]);
void acquisisci_barca(int v[], int lun, int barca);
void stampa(cella m[][N]);
void stampa_attacchi(cella m[][N]);
int vinto(cella m1[][N], cella m2[][N]);
void schiaccia_invio_per_continuare_1();
void schiaccia_invio_per_continuare_2();
void schiaccia_invio_per_continuare_solo_invio();

int main(){
	int indice_giocatore=1,prima_coordinata,seconda_coordinata;
	printf("Istruzioni: ci sono 7 barche, 2 lunghe 1 casella, 2 da 2, 1 da 3, 1 da 4 e 1 da 5.\n");
	printf("Inserisci le tue barche e colpisci quelle del tuo avversario!!!\n");
	printf("La lettera A indica l'acqua, la lettera B indica che c'e' un pezzo di barca.\n");
	printf("La tabella in cui si gioca e' una 10x10 e per inserire le barche bisogna digitare le coordinate.\n");
	printf("Ad esempio se volessi inserire un pezzo di una barca nella casella (3,7), dovrei digitare come prima coordinata 3 e come seconda 7.\n");
	printf("Le coordinate vanno da (1,1) a (10,10).\n");
	printf("Ricordati che non si possono inserire barche in diagonale.\n");
	printf("Giocatore 1 posiziona le tue barche:\n\n");
	cella tab1[N][N];
	cella tab2[N][N];
	inizializza_tab(tab1);
	inizializza_tab(tab2);
	genera_tab(tab1);
	printf("Il tuo campo di gioco e' questo:\n\n");
	stampa(tab1);
	schiaccia_invio_per_continuare_1();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\nGiocatore 2 posiziona le tue barche:\n\n");
	genera_tab(tab2);
	printf("Il tuo campo di gioco e' questo:\n\n");
	stampa(tab2);
	schiaccia_invio_per_continuare_2();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	while(vinto(tab1,tab2)==0){
		if(indice_giocatore%2==1){
			printf("\nGiocatore 1 e' il tuo turno.\n");
			printf("Premi invio per vedere di seguito il tuo campo di gioco:\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa(tab1);
			printf("\n\nPremi invio per vedere di seguito dove ti ha attaccato l'avversario fino ad ora (la lettera O indica che non ha ancora attaccato quelle coordinate, la lettera X indica che ha attaccato quelle coordinate):\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa_attacchi(tab1);
			printf("\n\nOra devi decidere dove vuoi attaccare, premi invio per vedere dove hai attaccato fino ad ora il campo del tuo avversario: (la lettera O indica che non hai ancora attaccato quelle coordinate, la lettera X indica che hai gia' attaccato quelle coordinate)\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa_attacchi(tab2);
			printf("\n\nInserisci la prima coordinata di dove vuoi colpire: ");
			scanf("%d",&prima_coordinata);
			while(!(prima_coordinata>=1 && prima_coordinata<=10)){
				printf("Deve essere compresa tra 1 e 10, inserisci la prima coordinata di dove vuoi colpire: ");
				scanf("%d",&prima_coordinata);
			}
			printf("Inserisci la seconda coordinata di dove vuoi colpire: ");
			scanf("%d",&seconda_coordinata);
			while(!(seconda_coordinata>=1 && seconda_coordinata<=10)){
				printf("Deve essere compresa tra 1 e 10, inserisci la seconda coordinata di dove vuoi colpire: ");
				scanf("%d",&seconda_coordinata);
			}
			if(tab2[prima_coordinata-1][seconda_coordinata-1].pezzo_barca==1){
				if(tab2[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca>1)
					printf("Complimenti giocatore 1, hai colpito una barca lunga %d pezzi!!!\n",tab2[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca);
				else
					printf("Complimenti giocatore 1, hai colpito una barca lunga %d pezzo!!!\n",tab2[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca);
				tab2[prima_coordinata-1][seconda_coordinata-1].colpito=1;
			}
			else
				printf("Mi dispiace giocatore 1, hai colpito l'acqua.");
			tab2[prima_coordinata-1][seconda_coordinata-1].attaccata=1;
			indice_giocatore++;
			schiaccia_invio_per_continuare_1();
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		else{
			printf("\nGiocatore 2 e' il tuo turno.\n");
			printf("Premi invio per vedere di seguito puoi vedere il tuo campo di gioco:\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa(tab2);
			printf("\n\nPremi invio per vedere di seguito puoi vedere dove ti ha attaccato l'avversario fino ad ora (la lettera O indica che non ha ancora attaccato quelle coordinate, la lettera X indica che ha attaccato quelle coordinate):\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa_attacchi(tab2);
			printf("\n\nOra devi decidere dove vuoi attaccare, premi invio per vedere dove hai attaccato fino ad ora il campo del tuo avversario: (la lettera O indica che non hai ancora attaccato quelle coordinate, la lettera X indica che hai gia'' attaccato quelle coordinate)\n\n");
			schiaccia_invio_per_continuare_solo_invio();
			stampa_attacchi(tab1);
			printf("\n\nInserisci la prima coordinata di dove vuoi colpire: ");
			scanf("%d",&prima_coordinata);
			while(!(prima_coordinata>=1 && prima_coordinata<=10)){
				printf("Deve essere compresa tra 1 e 10, inserisci la prima coordinata di dove vuoi colpire: ");
				scanf("%d",&prima_coordinata);
			}
			printf("Inserisci la seconda coordinata di dove vuoi colpire: ");
			scanf("%d",&seconda_coordinata);
			while(!(seconda_coordinata>=1 && seconda_coordinata<=10)){
				printf("Deve essere compresa tra 1 e 10, inserisci la seconda coordinata di dove vuoi colpire: ");
				scanf("%d",&seconda_coordinata);
			}
			if(tab1[prima_coordinata-1][seconda_coordinata-1].pezzo_barca==1){
				if(tab1[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca>1)
					printf("Complimenti giocatore 2, hai colpito una barca lunga %d pezzi!!!\n",tab1[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca);
				else
					printf("Complimenti giocatore 2, hai colpito una barca lunga %d pezzo!!!\n",tab1[prima_coordinata-1][seconda_coordinata-1].lunghezza_barca);
				tab1[prima_coordinata-1][seconda_coordinata-1].colpito=1;
			}
			else
				printf("Mi dispiace giocatore 2, hai colpito l'acqua.\n");
			tab1[prima_coordinata-1][seconda_coordinata-1].attaccata=1;
			indice_giocatore++;
			schiaccia_invio_per_continuare_2();
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
	}
	if(vinto(tab1,tab2)==1)
		printf("\nHa vinto il giocatore 1!!!");
	else
		printf("\nHa vinto il giocatore 2!!!");
	return 0;
}

int vinto(cella m1[][N], cella m2[][N]){
	int i,j,sum=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(m2[i][j].colpito==1 && m2[i][j].pezzo_barca==1)
				sum++;
		}
	}
	if(sum==4) //18
		return 1;
	sum=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(m1[i][j].colpito==1 && m1[i][j].pezzo_barca==1)
				sum++;
		}
	}
	if(sum==4) //18
		return 2;
	return 0;
}

void stampa_attacchi(cella m[][N]){
	int i,j;
	printf("   ");
	for(i=0;i<N;i++){
		printf("%3d",i+1);
	}
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j==0)
				printf("%3d",i+1);
			if(m[i][j].attaccata==1)
				printf("%3c",'X');
			else
				printf("%3c",'O');
		}
		printf("\n");
	}
}

void stampa(cella m[][N]){
	int i,j;
	printf("   ");
	for(i=0;i<N;i++){
		printf("%3d",i+1);
	}
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j==0)
				printf("%3d",i+1);
			if(m[i][j].pezzo_barca==1)
				printf("%3c",'B');
			else
				printf("%3c",'A');
		}
		printf("\n");
	}
}

void acquisisci_barca(int v[], int lun, int barca, cella m[][N]){
	int i,j=0,k,esiste=0,appena_inserito=0,modo_di_disporre=-1 /*1 per riga e 2 per colonna*/;
	printf("Inserisci le coordinate per la barca numero %d di lunghezza %d\n",barca,lun);
	for(i=0;i<lun;i++){
		printf("Inserisci la prima coordinata del pezzo %d della barca: ",i+1);
		scanf("%d",&v[j]);
		while(!(v[j]>=1 && v[j]<=10)){
			printf("Deve essere compresa tra 1 e 10, inserisci la prima coordinata del pezzo %d della barca: ",i+1);
			scanf("%d",&v[j]);
		}
		j++;
		printf("Inserisci la seconda coordinata del pezzo %d della barca: ",i+1);
		scanf("%d",&v[j]);
		while(!(v[j]>=1 && v[j]<=10)){
			printf("Deve essere compresa tra 1 e 10, inserisci la seconda coordinata del pezzo %d della barca: ",i+1);
			scanf("%d",&v[j]);
		}
		j++;
		esiste=0;
		if(m[v[j-2]-1][v[j-1]-1].pezzo_barca==1){
			printf("\nHai inserito dove c'era gia' un pezzo di barca!!!\n");
			i--;
			j=j-2;
			esiste=1;
		}
		appena_inserito=0;
		for(k=0;k<j-3 && esiste==0 && appena_inserito==0;k=k+2){
			if(v[k]==v[j-2] && v[k+1]==v[j-1]){
				printf("\nHai appena inserito questo pezzo poco fa, ti sei dimenticato?\n");
				i--;
				j=j-2;
				appena_inserito=1;
			}
		}
		if(i==1 && esiste==0 && appena_inserito==0){
			if(v[0]==v[2] && (v[1]==v[3]-1 || v[1]==v[3]+1)){
				modo_di_disporre=1; //per riga
			}
			else if(v[1]==v[3] && (v[0]==v[2]-1 || v[0]==v[2]+1))
				modo_di_disporre=2; //per colonna
			else{
				printf("\nHai inserito in modo sbagliato la barca!!!\n");
				i--;
				j=j-2;
			}
		}
		if(i>1 && esiste==0 && appena_inserito==0){
			if(modo_di_disporre==1 && (v[j-4]!=v[j-2] || (v[j-3]!=v[j-1]-1 && v[j-3]!=v[j-1]+1))){
				printf("\nHai inserito in modo sbagliato la barca!!!\n");
				i--;
				j=j-2;
			}
			if(modo_di_disporre==2 && (v[j-3]!=v[j-1] || (v[j-4]!=v[j-2]-1 && v[j-4]!=v[j-2]+1))){
				printf("\nHai inserito in modo sbagliato la barca!!!\n");
				i--;
				j=j-2;
			}
		}
	}
}

void genera_tab(cella m[][N]){
	int i,j,k,r,c,numero_barche=3 /*7*/, vettore_lunghezza_barche[7]={1,1,2,2,3,4,5}, indici_casella[N]={0,0,0,0,0,0,0,0,0,0};
	for(i=0;i<numero_barche;i++){
		for(j=0;j<N;j++){
			indici_casella[j]=0;
		}
		acquisisci_barca(indici_casella,vettore_lunghezza_barche[i],i+1,m);
		r=0;
		c=1;
		for(k=0;k<N/2 && indici_casella[r]!=0;k++){
			m[indici_casella[r]-1][indici_casella[c]-1].pezzo_barca=1;
			m[indici_casella[r]-1][indici_casella[c]-1].lunghezza_barca=vettore_lunghezza_barche[i];
			r=r+2;
			c=c+2;
		}
	}
}

void inizializza_tab(cella m[][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			m[i][j].colpito=0;
			m[i][j].pezzo_barca=0;
			m[i][j].lunghezza_barca=0;
			m[i][j].attaccata=0;
		}
	}
}

