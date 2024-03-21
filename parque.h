#ifndef PARQUE_H_
#define PARQUE_H_



struct _parque{
	ticket * ticket;
	int numTickets;
	int capacidade;
    float caixa;
};


typedef struct _parque * parque;


parque criaParque();

void destroiParqueETickets(parque meuParque);

void daSaidaTicket(ticket meuTicket,int hora,int minutos);

void incCapacidadeParque(parque p);

int daLotacaoParque(parque p);

float daCaixaParque(parque p);

int existeParque(parque p,char * mat);

int entradaCarroParque(parque p,char * mat,int h,int m);

float removeTicketParque(parque p,char * mat,int hora,int minuto);





#endif 
