#include "Fantasists.h"

Fantasists::Fantasists() {

		SetType(3);
		SetErr(false);
		cout << "������� ��� ��������:" << endl << "���: ";
		cin.ignore(256, '\n');
		getline(cin, this->FantasistsFIO.Name);
		cout << "�������: ";
		getline(cin, this->FantasistsFIO.Surname);
		cout << "��������: ";
		getline(cin, this->FantasistsFIO.Patronymic);
		cout << "������� ��������� ������������: ";
		getline(cin, this->works2);

		cout << "������� ���������� � ������� �������, ������ �� ������: " << endl << "������� '1', ���� ������ �����, ������� '2', ���� ������ �� ����� " << endl;
		//getline(cin, this->films);
		int fi;
		cin >> fi;
		switch (fi) {
		case 1:
			this->films = "��";
			break;
		case 2:
			this->films = "���";
			break;
		default:
			break;
		}
}

Fantasists::Fantasists(ifstream& fin) {
	SetType(3);
	fin.ignore(256, '\n');
	getline(fin, this->FantasistsFIO.Name);
	getline(fin, this->FantasistsFIO.Surname);
	getline(fin, this->FantasistsFIO.Patronymic);
	getline(fin, this->works2);
	getline(fin, this->films);
}

Fantasists::~Fantasists() {
	cout << "��� ������ ���������� ������ Fantasists" << endl;
}

void Fantasists::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string s_temp;
	char f_temp;
	cout << "��������, ��� ����� ���������������:" << endl
		<< "1 - ���" << endl
		<< "2 - ������������" << endl
		<< "3 - ������� �������" << endl
		<< "0 - ������" << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "������: ";
		cout << this->FantasistsFIO.Name << " "
			<< this->FantasistsFIO.Surname << " "
			<< this->FantasistsFIO.Patronymic << endl
			<< "�� ��� ��������:  ��� >> ";
		cin.ignore(256, '\n');
		getline(cin, fio_temp.Name);
		cout << "\t������� >> ";
		getline(cin, fio_temp.Surname);
		cout << "\t�������� >> ";
		getline(cin, fio_temp.Patronymic);
		FantasistsFIO = fio_temp;
		break;
	case 2:
		cout << "������: ";
		cout << this->works2 << endl
			<< "�� ��� �������� >> ";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		works2 = s_temp;
		break;
	case 3:
		cout << "������: ";
		cout << this->films << endl
			<< "�� ��� �������� >> ";
		cin.ignore(256, '\n');
		//getline(cin, s_temp);
		cout << "������� '1', ���� ������ �����, ������� '2', ���� ������ �� ����� " << endl;
		int fii;
		cin >> fii;
		switch (fii) {
		case 1:
			this->films = "��";
			break;
		case 2:
			this->films = "���";
			break;
		default:
			break;
		}		
		//films = s_temp;
		break;
	default:
		break;
	}
}

void Fantasists::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->FantasistsFIO.Name << endl
		<< this->FantasistsFIO.Surname << endl
		<< this->FantasistsFIO.Patronymic << endl
		<< this->works2 << endl
		<< this->films << endl;
}

void Fantasists::Print(ostream& out) {
	out << "�������:" << endl
		<< "���: " << this->FantasistsFIO.Name << " " << this->FantasistsFIO.Surname << " " << this->FantasistsFIO.Patronymic << endl
		<< "������������: " << this->works2 << endl
		<< "������� �������: " << this->films << endl
		<< " " << endl;
}