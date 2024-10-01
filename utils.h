#ifndef __utils_C
#define __utils_C
/*
       This header file contains some useful functions
*/
#include <stdio.h>

void schiaccia_invio_per_continuare_1(){
       printf("\nGiocatore 1 premi invio per far giocare il giocatore 2...\n");
       fflush(stdin);
       while(getchar()!='\n');
}

void schiaccia_invio_per_continuare_2(){
       printf("\nGiocatore 2 premi invio per far giocare il giocatore 1...\n");
       fflush(stdin);
       while(getchar()!='\n');
}

void schiaccia_invio_per_continuare_solo_invio(){
       fflush(stdin);
       while(getchar()!='\n');
}

#endif