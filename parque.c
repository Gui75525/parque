#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ticket.h"
#include "parque.h"


#define MAXL 150


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


int existeParque(parque p,char * mat){
    
    for (int i = 0; i < p->numTickets; i++)
    {
        if(strcmp(p->ticket[i]->matricula, mat) == 0){
            return i;
        }
        
    }
    return -1;
    
}

int entradaCarroParque(parque p,char * mat,int h,int m){

    
    for(int i = 0; i < p->numTickets; i++){

        if (strcmp(p->ticket[i]->matricula, mat) == 0)
        {
            return 0;
        }
    }
    ticket t = criaTicket(mat, h, m);

        p->ticket[p->numTickets] = t;

        p->numTickets = p->numTickets + 1;
        
        return 1;
}





float removeTicketParque(parque p, char *matricula, int hora, int minuto){
    
    float valor;
    int me, he;
    int horafinal, minutofinal;
    int posicao = existeParque(p, matricula);

    he = p->ticket[posicao]->h_entrada; 
    me = p->ticket[posicao]->m_entrada; 


    horafinal = hora - he;
    minutofinal = minuto - me;

    if(minutofinal > 0){
        horafinal = horafinal + 1;
    }

    if(horafinal == 1){
        valor = 1.5;
    }

    if (horafinal == 2)
    {
        valor = 2.5;
    }

    if (horafinal == 3)
    {
        valor = 3.5;
    }

    if (horafinal > 3)
    {
        valor = 3.5 + (horafinal - 3) * 0.75;
    }
    
    

    p->caixa += valor;

    destroiTicket(p->ticket[posicao]);

    for(int i=posicao; i<p->numTickets; i++){
        p->ticket[i] = p->ticket[i+1];
    }
    p->numTickets--;
    return valor;
}




