#pragma once
#include "PrintEdition.h"
using namespace std;

class Poets : public PrintEdition {
private:
	FIO PoetsFIO; //���
	string year; //���� �����
	string works; //������������
public:
	Poets();
	Poets(ifstream& fin);
	~Poets();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};