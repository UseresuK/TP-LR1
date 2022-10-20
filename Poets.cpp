#include "Poets.h"

Poets::Poets() {
	SetType(1);
	SetErr(false);
	cout << "Введите ФИО поэта:" << endl << "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->PoetsFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->PoetsFIO.Surname);
		cout << "Отчество: ";
		getline(cin, this->PoetsFIO.Patronymic);
		cout << "Введите годы жизни: ";
		getline(cin, this->year);
		cout << "Введите известные произведения: ";
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
	cout << "Был вызван деструктор класса Poets" << endl;
}

void Poets::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string s_temp;
	cout << "Выберите, что нужно отредактировать:" << endl
		<< "1 - ФИО" << endl
		<< "2 - Годы жизни" << endl
		<< "3 - Произведения" << endl
		<< "0 - Отмена" << endl;
	cin >> choose;
		switch (choose) {
		case 1:
			cout << "Запись: ";
			cout << this->PoetsFIO.Name << " "
				<< this->PoetsFIO.Surname << " "
				<< this->PoetsFIO.Patronymic << endl
				<< "На что изменить:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.Surname);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.Patronymic);
			PoetsFIO = fio_temp;
			break;
		case 2:
			cout << "Запись: ";
			cout << this->year << endl
				<< "На что изменить >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			year = s_temp;
			break;
		case 3:
			cout << "Запись: ";
			cout << this->works << endl
				<< "На что изменить >> ";
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
	out << "Поэт:" << endl
		<< "ФИО: " << this->PoetsFIO.Name << " " << this->PoetsFIO.Surname << " " << this->PoetsFIO.Patronymic << endl
		<< "Годы жизни: " << this->year << endl
		<< "Произведения: " << this->works << endl
		<< " " << endl;
}