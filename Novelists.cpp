#include "Novelists.h"

Novelists::Novelists() {
	SetType(2);
	SetErr(false);
	cout << "������� ��� ���������:" << endl << "���: ";
	    cin.ignore(256, '\n');
		getline(cin, this->NovelistsFIO.Name);
		cout << "�������: ";
		getline(cin, this->NovelistsFIO.Surname);
		cout << "��������: ";
		getline(cin, this->NovelistsFIO.Patronymic);
		cout << "������� ���� �����: ";
		getline(cin, this->years);
		cout << "������� ��������� ������������: ";
		getline(cin, this->works1);
		cout << "������� ���������: ";
		getline(cin, this->biog);
	
}

Novelists::Novelists(ifstream& fin) {
	SetType(2);
	fin.ignore(256, '\n');
	getline(fin, this->NovelistsFIO.Name);
	getline(fin, this->NovelistsFIO.Surname);
	getline(fin, this->NovelistsFIO.Patronymic);
	getline(fin, this->years);
	getline(fin, this->works1);
	getline(fin, this->biog);
}

Novelists::~Novelists() {
	cout << "��� ������ ���������� ������ Novelists";
}

void Novelists::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "��������, ��� ����� ���������������:" << endl
		<< "1 - ���" << endl
		<< "2 - ���� �����" << endl
		<< "3 - ������������" << endl
		<< "4 - ���������" << endl
		<< "0 - ������" << endl;
	cin >> choose;

		switch (choose) {
		case 1:
			cout << "������: ";
			cout << this->NovelistsFIO.Name << " "
				<< this->NovelistsFIO.Surname << " "
				<< this->NovelistsFIO.Patronymic << endl
				<< "�� ��� ��������:  ��� >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\t������� >> ";
			getline(cin, fio_temp.Surname);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.Patronymic);
			NovelistsFIO = fio_temp;
			break;
		case 2:
			cout << "������: ";
			cout << this->years << endl
				<< "�� ��� �������� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			years = s_temp;
			break;
		case 3:
			cout << "������: ";
			cout << this->works1 << endl
				<< "�� ��� �������� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			works1 = s_temp;
			break;
			break;
		case 4:
			cout << "������: ";
			cout << this->biog << endl
				<< "�� ��� �������� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			biog = s_temp;
			break;
		default:
			break;
		}
	
}

void Novelists::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->NovelistsFIO.Name << endl
		<< this->NovelistsFIO.Surname << endl
		<< this->NovelistsFIO.Patronymic << endl
		<< this->years << endl
		<< this->works1 << endl
		<< this->biog << endl;
}

void Novelists::Print(ostream& out) {
	out << "��������: " << endl
		<< "���: " << this->NovelistsFIO.Name << " " << this->NovelistsFIO.Surname << " " << this->NovelistsFIO.Patronymic << endl
		<< "���� �����: " << this->years << endl
		<< "������������: " << this->works1 << endl
		<< "���������: " << this->biog << endl
		<< " " << endl;
}