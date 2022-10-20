#pragma once
#include "PrintEdition.h"
using namespace std;

class Novelists : public PrintEdition {
private:
	FIO NovelistsFIO; //ФИО
	string years; //годы жизни
	string works1; //произведения
	string biog; //биография
public:
	Novelists();
	Novelists(ifstream& fin);
	~Novelists();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};