#include "Poets.h"

Poets::Poets() {
	SetType(1);
	SetErr(false);
	cout << "������� ��� �����:" << endl << "���: ";
		cin.ignore(256, '\n');
		getline(cin, this->PoetsFIO.Name);
		cout << "�������: ";
		getline(cin, this->PoetsFIO.Surname);
		cout << "��������: ";
		getline(cin, this->PoetsFIO.Patronymic);
		cout << "������� ���� �����: ";
		getline(cin, this->year);
		cout << "������� ��������� ������������: ";
		getline(cin, this->works);

}

Poets::Poets(ifstream& fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline(fin, this->PoetsFIO.Name);
	getline(fin, this->PoetsFIO.Surname);
	getline(fin, this->PoetsFIO.Patronymic);
	getline(fin, this->year);
	getline(fin, this->works);
}

Poets::~Poets() {
	cout << "��� ������ ���������� ������ Poets" << endl;
}

void Poets::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "��������, ��� ����� ���������������:" << endl
		<< "1 - ���" << endl
		<< "2 - ���� �����" << endl
		<< "3 - ������������" << endl
		<< "0 - ������" << endl;
	cin >> choose;
		switch (choose) {
		case 1:
			cout << "������: ";
			cout << this->PoetsFIO.Name << " "
				<< this->PoetsFIO.Surname << " "
				<< this->PoetsFIO.Patronymic << endl
				<< "�� ��� ��������:  ��� >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\t������� >> ";
			getline(cin, fio_temp.Surname);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.Patronymic);
			PoetsFIO = fio_temp;
			break;
		case 2:
			cout << "������: ";
			cout << this->year << endl
				<< "�� ��� �������� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			year = s_temp;
			break;
		case 3:
			cout << "������: ";
			cout << this->works << endl
				<< "�� ��� �������� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			works = s_temp;
			break;
		default:
			break;
		}
}

void Poets::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->PoetsFIO.Name << endl
		<< this->PoetsFIO.Surname << endl
		<< this->PoetsFIO.Patronymic << endl
		<< this->year << endl
		<< this->works << endl;
}

void Poets::Print(ostream& out) {
	out << "����:" << endl
		<< "���: " << this->PoetsFIO.Name << " " << this->PoetsFIO.Surname << " " << this->PoetsFIO.Patronymic << endl
		<< "���� �����: " << this->year << endl
		<< "������������: " << this->works << endl
		<< " " << endl;
}