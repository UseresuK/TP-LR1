#pragma once
#include "PrintEdition.h"
using namespace std;

class Fantasists : public PrintEdition {
private:
	FIO FantasistsFIO; //���
	string works2; //������������
	string films; //���������� � ������� ������� �� ������
public:
	Fantasists();
	Fantasists(ifstream& fin);
	~Fantasists();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};