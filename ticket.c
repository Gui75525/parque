#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ticket.h"

/* Constantes do TAD aluno */


#define MAXMAT 10





ticket criaTicket(char * matricula, int hora, int minutos){
	ticket a;
	a = (ticket) malloc(sizeof(struct _ticket));
	if (a == NULL) return NULL;

    strcpy(a->matricula, matricula);
    a->h_entrada = hora;
    a->m_entrada = minutos;
	
	return a;
}

void destroiTicket(ticket meuTicket){
    free(meuTicket);
}


void daSaidaTicket(ticket meuTicket,int hora,int minutos){

    int horastotais = hora - meuTicket->h_entrada;
    int minutostotais = minutos - meuTicket->m_entrada;

    if(minutostotais == 0){
        meuTicket->estadia = horastotais;
    }
    else{
        if (minutostotais > 0)
        {
            meuTicket->estadia = horastotais + 1;
        }
        else{
            meuTicket->estadia = horastotais + 2;
        }
    }

}



