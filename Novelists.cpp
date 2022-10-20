#include "Novelists.h"

Novelists::Novelists() {
	SetType(2);
	SetErr(false);
	cout << "Введите ФИО романиста:" << endl << "Имя: ";
	    cin.ignore(256, '\n');
		getline(cin, this->NovelistsFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->NovelistsFIO.Surname);
		cout << "Отчество: ";
		getline(cin, this->NovelistsFIO.Patronymic);
		cout << "Введите годы жизни: ";
		getline(cin, this->years);
		cout << "Введите известные произведения: ";
		getline(cin, this->works1);
		cout << "Введите биографию: ";
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
	cout << "Был вызван деструктор класса Novelists";
}

void Novelists::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "Выберите, что нужно отредактировать:" << endl
		<< "1 - ФИО" << endl
		<< "2 - Годы жизни" << endl
		<< "3 - Произведения" << endl
		<< "4 - Биография" << endl
		<< "0 - Отмена" << endl;
	cin >> choose;

		switch (choose) {
		case 1:
			cout << "Запись: ";
			cout << this->NovelistsFIO.Name << " "
				<< this->NovelistsFIO.Surname << " "
				<< this->NovelistsFIO.Patronymic << endl
				<< "На что изменить:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.Surname);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.Patronymic);
			NovelistsFIO = fio_temp;
			break;
		case 2:
			cout << "Запись: ";
			cout << this->years << endl
				<< "На что изменить >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			years = s_temp;
			break;
		case 3:
			cout << "Запись: ";
			cout << this->works1 << endl
				<< "На что изменить >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			works1 = s_temp;
			break;
			break;
		case 4:
			cout << "Запись: ";
			cout << this->biog << endl
				<< "На что изменить >> ";
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
	out << "Романист: " << endl
		<< "ФИО: " << this->NovelistsFIO.Name << " " << this->NovelistsFIO.Surname << " " << this->NovelistsFIO.Patronymic << endl
		<< "Годы жизни: " << this->years << endl
		<< "Произведения: " << this->works1 << endl
		<< "Биография: " << this->biog << endl
		<< " " << endl;
}