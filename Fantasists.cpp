#include "Fantasists.h"

Fantasists::Fantasists() {

		SetType(3);
		SetErr(false);
		cout << "Введите ФИО фантаста:" << endl << "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->FantasistsFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->FantasistsFIO.Surname);
		cout << "Отчество: ";
		getline(cin, this->FantasistsFIO.Patronymic);
		cout << "Введите известные произведения: ";
		getline(cin, this->works2);

		cout << "Введите информацию о наличии фильмов, снятых по книгам: " << endl << "Нажмите '1', если фильмы сняты, нажмите '2', если фильмы не сняты " << endl;
		//getline(cin, this->films);
		int fi;
		cin >> fi;
		switch (fi) {
		case 1:
			this->films = "да";
			break;
		case 2:
			this->films = "нет";
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
	cout << "Был вызван деструктор класса Fantasists" << endl;
}

void Fantasists::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string s_temp;
	char f_temp;
	cout << "Выберите, что нужно отредактировать:" << endl
		<< "1 - ФИО" << endl
		<< "2 - Произведения" << endl
		<< "3 - Наличие фильмов" << endl
		<< "0 - Отмена" << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "Запись: ";
		cout << this->FantasistsFIO.Name << " "
			<< this->FantasistsFIO.Surname << " "
			<< this->FantasistsFIO.Patronymic << endl
			<< "На что изменить:  Имя >> ";
		cin.ignore(256, '\n');
		getline(cin, fio_temp.Name);
		cout << "\tФамилия >> ";
		getline(cin, fio_temp.Surname);
		cout << "\tОтчество >> ";
		getline(cin, fio_temp.Patronymic);
		FantasistsFIO = fio_temp;
		break;
	case 2:
		cout << "Запись: ";
		cout << this->works2 << endl
			<< "На что изменить >> ";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		works2 = s_temp;
		break;
	case 3:
		cout << "Запись: ";
		cout << this->films << endl
			<< "На что изменить >> ";
		cin.ignore(256, '\n');
		//getline(cin, s_temp);
		cout << "Нажмите '1', если фильмы сняты, нажмите '2', если фильмы не сняты " << endl;
		int fii;
		cin >> fii;
		switch (fii) {
		case 1:
			this->films = "да";
			break;
		case 2:
			this->films = "нет";
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
	out << "Фантаст:" << endl
		<< "ФИО: " << this->FantasistsFIO.Name << " " << this->FantasistsFIO.Surname << " " << this->FantasistsFIO.Patronymic << endl
		<< "Произведения: " << this->works2 << endl
		<< "Наличие фильмов: " << this->films << endl
		<< " " << endl;
}