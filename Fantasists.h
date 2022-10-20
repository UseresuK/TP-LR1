#pragma once
#include "PrintEdition.h"
using namespace std;

class Fantasists : public PrintEdition {
private:
	FIO FantasistsFIO; //ФИО
	string works2; //произведения
	string films; //информация о наличии фильмов по книгам
public:
	Fantasists();
	Fantasists(ifstream& fin);
	~Fantasists();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};