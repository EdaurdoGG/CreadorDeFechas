#pragma once
#include <string>
#include <vector>
using namespace std;

namespace Act
{
	class Fecha
	{
	public:
		int dia;
		int mes;
		int year;

	public:

		//Constructo y Destructor;
		Fecha(int _dia = 0, int _mes = 0, int _year = 0);
		~Fecha();

		//Setter y Getters

		void setD(int _dia);
		void setM(int _mes);
		void setA(int _year);

		int getD();
		int getM();
		int getA();

		string getFddmmyyyy();
		string getFmmddyyyy();
		string getyyyymmdd();

		string convertirUnidades(int num);
		string convertirDecenas(int num);
		string convertirCentenas(int num);
		string convertirMiles(int num);
		string mesALetras(int mes);
		string fechaLetras(int _dia, int _mes, int _year);
		string fechaLetrasMes(int _dia, int _mes, int _year);
		string fechaLetrasAño(int _dia, int _mes, int _year);
	};
};

