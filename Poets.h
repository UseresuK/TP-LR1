#pragma once
#include "PrintEdition.h"
using namespace std;

class Poets : public PrintEdition {
private:
	FIO PoetsFIO; //ФИО
	string year; //годы жизни
	string works; //произведения
public:
	Poets();
	Poets(ifstream& fin);
	~Poets();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};