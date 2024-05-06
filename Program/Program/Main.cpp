#include <iostream>
#include <string>

extern const int M = 90;
extern int collisionCount = 0;

#include "LinearFunc.h"
#include "ChainFunc.h"

using namespace std;

int main() {
	system("chcp 1251 > null");

	int navig, subnavig, count = 100;
	int tableMode = 0; // 1 - Linear, 2 - Chain
	string buffer;

	bool flag;

	HashTableLinear tableL;
	HashTableChain tableC;

	do {

		cout << "1. Создание таблицы" << endl;
		cout << "2. Просмотр таблицы" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Добавление элемента" << endl;
		cout << "5. Удаление элемента" << endl;
		cout << "6. Сохранение таблицы в файле" << endl;
		cout << "7. Чтение таблицы из файла" << endl;
		cout << "8. Отчистка таблицы" << endl;
		cout << "0. Завершение программы" << endl;
		cout << endl << ">";

		cin >> navig;
		cin.ignore();

		switch (navig)
		{
		case 1:
			cout << "Выберете тип таблицы: 1. Линейный 2. Цепной" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();
			
			if (subnavig == 1) {
				tableMode = 1;
				clearTable(tableL);
				for (int i = 0; i < count; ++i) {
					makeHum(tableL);
				}
				cout << "Сгенерирована hash-таблица" << endl;

			}
			else if (subnavig == 2)
			{
				clearTable(tableC);
				tableMode = 2;
				for (int i = 0; i < count; ++i) {
					makeHum(tableC);
				}
				cout << "Сгенерирована hash-таблица" << endl;
			}
			else {
				cout << "Некорректный индекс" << endl;
			}
			
			cout << endl;
			break;

		case 2:
			if (tableMode == 1) {
				printTable(tableL);
				cout << "Число коллизий: " << collisionCount << endl;
			}
			else if (tableMode == 2) {
				printTable(tableC);
				cout << "Число коллизий: " << collisionCount << endl;
			}
			else {
				cout << "Таблица отсутствует" << endl;
			}
			cout << endl;
			break;

		case 3:
			if(!tableMode) {
				cout << "Таблица отсутствует" << endl << endl;
				break;
			}

			cout << "Введите ключ поиска: ";
			
			getline(cin, buffer);

			flag = false;

			if (tableMode == 1) {
				NodeLinear* node = get(tableL, buffer);
				flag = node != nullptr;
				if (flag) buffer = node->dat;
			}
			else if (tableMode == 2) {
				NodeChain* node = get(tableC, buffer);
				flag = node != nullptr;
				if (flag) buffer = node->dat;
			}
			
			if (flag) {
				cout << "Элемент найден: " << buffer << endl;
			}
			else {
				cout << "Элемент с заданным ключом не найден" << endl;
			}
			cout << endl;
			break;

		case 4:
			if (!tableMode) {
				cout << "Таблица отсутствует" << endl << endl;
				break;
			}

			cout << "Выберете режим добавления: 1. ДСЧ 2. Ручной" << endl;
			cout << endl << ">";
			cin >> subnavig;

			if (subnavig == 1) {
				if (tableMode == 1) {
					makeHum(tableL);
					cout << "Элемент добавлен";
				}
				else if (tableMode == 2) {
					makeHum(tableC);
					cout << "Элемент добавлен";
				}
			}
			if (subnavig == 2) {
				string s1;
				string s2;
				string s3;
				string custData;

				cout << "Введите через пробел: дата рождения, ФИО, номер паспорта" << endl;
				cin >> s1;
				cin >> s2;
				cin >> s3;

				custData = s2 + '|' + s1 + '|' + s3;

				if (tableMode == 1) {
					add(tableL, s1, custData);
					cout << "Элемент добавлен";
				}
				else if (tableMode == 2) {
					add(tableC, s1, custData);
					cout << "Элемент добавлен";
				}
			}
			else {
				cout << "Некорректный индекс" << endl;
			}
			cout << endl;
			break;

		case 5:
			if (!tableMode) {
				cout << "Таблица отсутствует" << endl << endl;
				break;
			}

			cout << "Выберете режим удаления: 1. По ключу 2. По данным" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();

			flag = false;

			if (subnavig == 1) {
				cout << "Введите ключ для удаления: ";
				
				getline(cin, buffer);

				if (tableMode == 1) {
					flag = removeByKey(tableL, buffer);
				}
				else if (tableMode == 2) {
					flag = removeByKey(tableC, buffer);
				}

				if (flag) {
					cout << "Элемент с заданным ключом удален" << endl;
				}
				else {
					cout << "Элемент с заданным ключом не найден" << endl;
				}
			}
			else if (subnavig == 2) {
				cout << "Введите данные для удаления: ";
				getline(cin, buffer);
				
				if (tableMode == 1) {
					flag = removeByData(tableL, buffer);
				}
				else if (tableMode == 2) {
					flag = removeByData(tableC, buffer);
				}

				if (flag) {
					cout << "Элемент с заданными данными удален" << endl;
				}
				else{
					cout << "Элемент с заданными данными не найден" << endl;
				}
			}
			else {
				cout << "Некорректный индекс" << endl;
			}
			cout << endl;
			break;

		case 6:
			if (tableMode == 1) {
				saveTable(tableL);
				cout << "Таблица сохранена" << endl;
			}
			else if (tableMode == 2) {
				saveTable(tableC);
				cout << "Таблица сохранена" << endl;
			}
			else {
				cout << "Таблица отсутствует" << endl;
			}
			cout << endl;
			break;

		case 7:
			cout << "Выберете тип таблицы: 1. Линейный 2. Цепной" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();

			if (subnavig == 1) {
				tableMode = 1;
				readTable(tableL);
				cout << "Востановлена hash-таблица" << endl;

			}
			else if (subnavig == 2)
			{
				tableMode = 2;
				readTable(tableC);
				cout << "Востановлена hash-таблица" << endl;
			}
			else {
				cout << "Некорректный индекс" << endl;
			}

			cout << endl;
			break;

		case 8:
			if (tableMode == 1) {
				clearTable(tableL);
				cout << "Таблица отчищена" << endl;
			}
			else if (tableMode == 2) {
				clearTable(tableC);
				cout << "Таблица отчищена" << endl;
			}
			else {
				cout << "Таблица отсутствует" << endl;
			}
			cout << endl;
			break;
		default:
			break;
		}

	} while (navig != 0);


	return 0;
}