#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ticket.h"
#include "parque.h"


#define MAXL 25


parque criaParque(){

    parque t = (parque) malloc (sizeof(struct _parque));
	if (t == NULL) return NULL;
	t->ticket = (ticket *) malloc (sizeof(ticket) * MAXL);
	if (t->ticket == NULL){
		free(t);
		return NULL;
	}
	t->numTickets = 0;
	t->capacidade = MAXL;
	return t;
}


void destroiParqueETickets(parque meuParque){
    
	for(int i = 0; i< meuParque->numTickets; i++)
		destroiTicket(meuParque->ticket[i]);
	    free(meuParque->ticket);
	    free(meuParque);
}


void entradaCarroParque(parque p, char * matricula, int hora, int minuto){
    if (p->numTickets == p->capacidade)
        incCapacidadeParque(p);
    p->ticket[p->numTickets++] = criaTicket(matricula, hora, minuto);
}

void incCapacidadeParque(parque p){
    int i = 0;
    /* Cria um vector com o dobro do tamanho */
    ticket * aux = (ticket *) malloc(sizeof (ticket)* p->capacidade * 2 );
    for(i=0; i<p->numTickets; i++)
        aux[i] = p->ticket[i];
    free(p->ticket);
    p->ticket = aux;
    p->capacidade = p->capacidade * 2;
}



float daCaixaParque(parque p){
    return p->caixa;
}

int daLotacaoParque(parque p){
    return p->numTickets;
}