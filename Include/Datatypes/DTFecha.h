#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha{
private:
	int Ano;
	int Mes;
	int Dia;
	int Horas;
	int Minutos;


public:
	DTFecha();
	DTFecha(int ano, int mes, int dia, int horas, int minutos);
	~DTFecha();

	int getAno();
	int getMes();
	int getDia();
	int getHoras();
	int getMinutos();
};

#endif