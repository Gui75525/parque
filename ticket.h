#ifndef TICKET_H_
#define TICKET_H_



struct _ticket{
	int h_entrada, m_entrada;
    int estadia;
    char matricula[10];
};


typedef struct _ticket * ticket;


ticket criaTicket(char * matricula,int hora,int minutos);

void destroiTicket(ticket meuTicket);

void daSaidaTicket(ticket meuTicket,int hora,int minutos);


#endif 

