#include "Fecha.h"
#include <string>
#include <vector>

using namespace std;
using namespace Act;

Fecha::Fecha(int _dia, int _mes, int _year)
	:dia{_dia}, mes{_mes}, year{_year}
{

}
Fecha::~Fecha()
{

}

void Fecha::setD(int _dia)
{
	dia = _dia;
}
void Fecha::setM(int _mes)
{
	mes = _mes;
}
void Fecha::setA(int _year)
{
	year = _year;
}

int Fecha::getD()
{
	return dia;
}
int Fecha::getM()
{
	return mes;
}
int Fecha::getA()
{
	return year;
}

string Fecha::getFddmmyyyy()
{
	string Date;

	Date = to_string(dia) + "/" + to_string(mes) + "/" + to_string(year);
	return Date;
}
string Fecha::getFmmddyyyy()
{
	string Date;

	Date = to_string(mes) + "/" + to_string(dia) + "/" + to_string(year);
	return Date;
}
string Fecha::getyyyymmdd()
{
	string Date;

	Date = to_string(year) + "/" + to_string(mes) + "/" + to_string(dia);
	return Date;
}

string Fecha::convertirUnidades(int num) {
	vector<string> unidades = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
	return unidades[num];

}
string Fecha::convertirDecenas(int num) {
	vector<string> decenas = { "", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
	vector<string> especiales = { "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve" };
	if (num < 10) return convertirUnidades(num);
	else if (num >= 11 && num <= 19) return especiales[num - 11];
	else {
		int u = num % 10;
		int d = num / 10;
		return (u == 0) ? decenas[d] : decenas[d] + " y " + convertirUnidades(u);
	}

}
string Fecha::convertirCentenas(int num) {
	vector<string> centenas = { "", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };
	if (num == 100) return "cien";
	int c = num / 100;
	int resto = num % 100;
	return (c == 0) ? convertirDecenas(resto) : centenas[c] + ((resto == 0) ? "" : " " + convertirDecenas(resto));

}
string Fecha::convertirMiles(int num) {
	if (num == 0) return "cero";
	int m = num / 1000;
	int resto = num % 1000;
	if (m == 0) return convertirCentenas(resto);
	if (m == 1) return "mil " + convertirCentenas(resto);
	return convertirCentenas(m) + " mil " + convertirCentenas(resto);

}
string Fecha::mesALetras(int _mes) {
	vector<string> meses = {
	   "", "enero", "febrero", "marzo", "abril", "mayo", "junio",
	   "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
	};
	return meses[_mes];

}
string Fecha::fechaLetras(int _dia, int _mes, int _year) {
	string diaLetras = convertirDecenas(_dia);
	string mesLetras = mesALetras(_mes);
	string anioLetras = convertirMiles(_year);
	return diaLetras + " de " + mesLetras + " del " + anioLetras;

}
string Fecha::fechaLetrasMes(int _dia, int _mes, int _year) {
	string diaLetras = convertirDecenas(_dia);
	string mesLetras = mesALetras(_mes);
	string anioLetras = convertirMiles(_year);
	return mesLetras + "  " + diaLetras + " del " + anioLetras;
}
string Fecha::fechaLetrasAño(int _dia, int _mes, int _year) {
	string diaLetras = convertirDecenas(_dia);
	string mesLetras = mesALetras(_mes);
	string anioLetras = convertirMiles(_year);
	return anioLetras + " de " + mesLetras + "  " + diaLetras;
}