#include "Keeper.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Keeper Edition;
	char menu = 0;
	do {
		try {
		   cout << "Выберите действие:" << endl
				<< "1 - Добавить данные" << endl
				<< "2 - Редактировать данные" << endl
				<< "3 - Удалить данные" << endl
				<< "4 - Сохранить данные в файл" << endl
				<< "5 - Загрузить данные из файла" << endl
				<< "6 - Вывести все имеющиеся данные" << endl
				<< "0 - Выход" << endl
				<< ">> ";
			cin >> menu;
			if ((!isdigit(menu)) && ((menu >= 7) || (menu <= -1))) {
				throw 1;
			}
			switch (menu) {
			case '0':
				break;
			case '1':
				Edition.Add();
				break;
			case '2':
				Edition.Edit();
				break;
			case '3':
				Edition.Del();
				break;
			case '4':
				Edition.Save();
				break;
			case '5':
				Edition.Load();
				break;
			case '6':
				cout << Edition;
				break;
			}
		}
		catch (int) {
			cout << "Переменная 'menu' - цифра от 0 до 6" << endl;
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}
