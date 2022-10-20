#include "Keeper.h"

int Choose() {
	int x = 0;
	cout << "�������� �����:" << endl
		<< "1 - �����" << endl
		<< "2 - ���������" << endl
		<< "3 - ��������" << endl
		<< ">> ";
	cin >> x;
	return x;
}

int count = 0;

Keeper::Keeper() {
	this->Value = nullptr;
	this->size = 0;
}

Keeper::~Keeper() {
	delete[] Value;
}

void Keeper::Add() {
	try {
		PrintEdition** temp = new PrintEdition * [size + 1];
		int i = 0;
		while (i < size) {
			temp[i] = Value[i];
			i++;
		}
		switch (Choose()) {
		case 1:
			temp[size] = new Poets;
			break;
		case 2:
			temp[size] = new Novelists; 
			break;
		case 3:
			temp[size] = new Fantasists;
			break;
		}
		if ((!temp[size]) || (temp[size]->GetErr()))
			throw 1;
		size++;
		if (Value)
			delete[] Value;
		Value = temp;
		cout << "�������� ���������" << endl;
	}
	catch (int) {
		cout << "������, �������� �� ���������" << endl;
	}
}

void Keeper::Add(int _type, ifstream& fin) {
	PrintEdition** temp = new PrintEdition * [size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	switch (_type) {
	case 1:
		temp[size] = new Poets(fin);
		break;
	case 2:
		temp[size] = new Novelists(fin);
		break;
	case 3:
		temp[size] = new Fantasists(fin);
		break;
	}
	::count++; 
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}

void Keeper::Edit() {
	int x;
	if (!size)
		cout << "���������� �����������" << endl;
	for (int i = 0; i < size; i++) {
		cout << "" << i + 1 << " - ";
		switch (Value[i]->GetType()) {
		case 1:
			cout << "����" << endl;
			break;
		case 2:
			cout << "��������" << endl;
			break;
		case 3:
			cout << "�������" << endl;
			break;
		default:
			break;
		}
	}
	try {
		cout << ">> ";
		cin >> x;
		if ((x < 1) || (x > size)) {
			throw 1;
		}
		x -= 1;
		Value[x]->Edit();
		if ((Value[x]->GetErr()) || (!Value[x]))
			cout << "�������������� �� �������" << endl;
		else
			cout << "�������������� ���������" << endl;
	}
	catch (int) {
		cout << "��������� ����� ����������" << endl;
	}
}

void Keeper::Del() {
	int x;
	if (!size)
		cout << "���������� �����������" << endl;
	for (int i = 0; i < size; i++) {
		switch (Value[i]->GetType()) {
		case 1:
			cout << "" << i + 1 << " - ����" << endl;
			break;
		case 2:
			cout << "" << i + 1 << " - ��������" << endl;
			break;
		case 3:
			cout << "" << i + 1 << " - �������" << endl;
			break;
		default:
			break;
		}
	}
	cout << ">> ";
	cin >> x;
	x -= 1;
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		cout << "�������� ���� ���������" << endl;
		size--;
	}
	else
	{
		PrintEdition** temp = new PrintEdition * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (x == i)
				continue;
			temp[j++] = Value[i];
		}
		delete[] Value;
		Value = temp;
		size--;
		cout << "�������� ���� ���������" << endl;
	}
}

void Keeper::Save() {
	ofstream fout("failik.txt");
	for (int i = 0; i < size; i++) {
		Value[i]->Save(fout);
	}
	fout.close();
	cout << "���������" << endl;
}

void Keeper::Load() {
	ifstream fin("failik.txt");
	if (fin.fail())
		cout << "���� ����" << endl;
	int type = 0;
	while (fin) {
		fin >> type;
		if (fin.peek() == -1)
			break;
		Add(type, fin);
	}
	fin.close();
	cout << "�������� ���������" << endl;

}

ostream& operator<< (ostream& out, Keeper& obj) {
	if (!obj.size) {
		cout << "���������� �����������" << endl;
		return out;
	}
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i]->Print(out);
	}
	return out;
}