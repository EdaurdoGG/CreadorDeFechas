#include <iostream>
#include <string>
#include <vector>

#include "Fecha.h"

using namespace std;
using namespace Act;

int main()
{
	//Varianbles de la clase Fecha
	int dia;
	int mes;
	int year;

	//Variable de control
	int Opcion;

	//Vectores
	vector<Fecha>DDMMYYYY;
	vector<Fecha>MMDDYYYY;
	vector<Fecha>YYYYMMDD;
	
	//Objetos

	Fecha Objeto;

	do
	{
		cout << "Bienvenido al creador de fechas" << endl;
		cout << "1. Fecha de la forma DD/MM/YYYY" << endl;
		cout << "2. Fecha de la forma MM/DD/YYYY" << endl;
		cout << "3. Fecha de la forma YYYY/MM/DD" << endl;
		cout << "4. Salir " << endl;
		cout << "Selecciona una de las opciones para comenzar:";
		cin >> Opcion;

		switch (Opcion)
		{
		case 1:
			cout << "Dime cual es el dia:\n" << endl;
			cin >> dia;
			cout << "Dime cual es el mes:\n" << endl;
			cin >> mes;
			cout << "Dime cual es el year:\n" << endl;
			cin >> year;

			Objeto.setD(dia);
			Objeto.setM(mes);
			Objeto.setA(year);

			if (((dia > 1) && (mes > 1) && (year > 1900)) && ((dia < 31) && (mes < 12) && (year < 3000)))
			{
				DDMMYYYY.push_back(Objeto);
				cout << Objeto.getFddmmyyyy();
				cout << "\n";
				cout << Objeto.fechaLetras(dia, mes, year) << endl;
			}
			else
			{
				cout<<"Fecha No valida\n"<<endl;
			}
			break;
		case 2:
			cout << "Dime cual es el dia:\n" << endl;
			cin >> dia;
			cout << "Dime cual es el mes:\n" << endl;
			cin >> mes;
			cout << "Dime cual es el year:\n" << endl;
			cin >> year;

			Objeto.setD(dia);
			Objeto.setM(mes);
			Objeto.setA(year);

			if (((dia > 1) && (mes > 1) && (year > 1900)) && ((dia < 31) && (mes < 12) && (year < 3000)))
			{
				MMDDYYYY.push_back(Objeto);
				cout << Objeto.getFmmddyyyy();
				cout << "\n";
				cout << Objeto.fechaLetrasMes (dia, mes, year) << endl;
			}
			else
			{
				cout << "Fecha No valida\n" << endl;
			}
			break;
		case 3:
			cout << "Dime cual es el dia:\n" << endl;
			cin >> dia;
			cout << "Dime cual es el mes:\n" << endl;
			cin >> mes;
			cout << "Dime cual es el year:\n" << endl;
			cin >> year;

			Objeto.setD(dia);
			Objeto.setM(mes);
			Objeto.setA(year);

			if (((dia > 1) && (mes > 1) && (year > 1900)) && ((dia < 31) && (mes < 12) && (year < 3000)))
			{
				YYYYMMDD.push_back(Objeto);
				cout << Objeto.getyyyymmdd();
				cout << "\n";
				cout << Objeto.fechaLetrasAño (dia, mes, year) << endl;
			}
			else
			{
				cout << "Fecha No valida\n" << endl;
			}
			break;
		default:
			break;
		}
		
		cout << endl << endl;
		system("pause");
		system("cls");

	} while(Opcion != 4);

	return 0;
}