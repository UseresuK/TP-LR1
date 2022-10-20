#pragma once
#include "PrintEdition.h"
using namespace std;

class Novelists : public PrintEdition {
private:
	FIO NovelistsFIO; //���
	string years; //���� �����
	string works1; //������������
	string biog; //���������
public:
	Novelists();
	Novelists(ifstream& fin);
	~Novelists();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};