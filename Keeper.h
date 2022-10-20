#pragma once
#include "PrintEdition.h"
#include "Novelists.h"
#include "Poets.h"
#include "Fantasists.h"
#include <fstream>
#include <iostream>
using namespace std;

class Keeper {
private:
	PrintEdition** Value;
	int size;
public:
	Keeper();
	~Keeper();
	void Add();
	void Add(int _type, ifstream& fin);
	void Edit();
	void Del();
	void Save();
	void Load();
	friend ostream& operator<< (ostream& out, Keeper& obj);
};