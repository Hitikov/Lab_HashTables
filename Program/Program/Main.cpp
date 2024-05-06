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

		cout << "1. �������� �������" << endl;
		cout << "2. �������� �������" << endl;
		cout << "3. ����� ��������" << endl;
		cout << "4. ���������� ��������" << endl;
		cout << "5. �������� ��������" << endl;
		cout << "6. ���������� ������� � �����" << endl;
		cout << "7. ������ ������� �� �����" << endl;
		cout << "8. �������� �������" << endl;
		cout << "0. ���������� ���������" << endl;
		cout << endl << ">";

		cin >> navig;
		cin.ignore();

		switch (navig)
		{
		case 1:
			cout << "�������� ��� �������: 1. �������� 2. ������" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();
			
			if (subnavig == 1) {
				tableMode = 1;
				clearTable(tableL);
				for (int i = 0; i < count; ++i) {
					makeHum(tableL);
				}
				cout << "������������� hash-�������" << endl;

			}
			else if (subnavig == 2)
			{
				clearTable(tableC);
				tableMode = 2;
				for (int i = 0; i < count; ++i) {
					makeHum(tableC);
				}
				cout << "������������� hash-�������" << endl;
			}
			else {
				cout << "������������ ������" << endl;
			}
			
			cout << endl;
			break;

		case 2:
			if (tableMode == 1) {
				printTable(tableL);
				cout << "����� ��������: " << collisionCount << endl;
			}
			else if (tableMode == 2) {
				printTable(tableC);
				cout << "����� ��������: " << collisionCount << endl;
			}
			else {
				cout << "������� �����������" << endl;
			}
			cout << endl;
			break;

		case 3:
			if(!tableMode) {
				cout << "������� �����������" << endl << endl;
				break;
			}

			cout << "������� ���� ������: ";
			
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
				cout << "������� ������: " << buffer << endl;
			}
			else {
				cout << "������� � �������� ������ �� ������" << endl;
			}
			cout << endl;
			break;

		case 4:
			if (!tableMode) {
				cout << "������� �����������" << endl << endl;
				break;
			}

			cout << "�������� ����� ����������: 1. ��� 2. ������" << endl;
			cout << endl << ">";
			cin >> subnavig;

			if (subnavig == 1) {
				if (tableMode == 1) {
					makeHum(tableL);
					cout << "������� ��������";
				}
				else if (tableMode == 2) {
					makeHum(tableC);
					cout << "������� ��������";
				}
			}
			if (subnavig == 2) {
				string s1;
				string s2;
				string s3;
				string custData;

				cout << "������� ����� ������: ���� ��������, ���, ����� ��������" << endl;
				cin >> s1;
				cin >> s2;
				cin >> s3;

				custData = s2 + '|' + s1 + '|' + s3;

				if (tableMode == 1) {
					add(tableL, s1, custData);
					cout << "������� ��������";
				}
				else if (tableMode == 2) {
					add(tableC, s1, custData);
					cout << "������� ��������";
				}
			}
			else {
				cout << "������������ ������" << endl;
			}
			cout << endl;
			break;

		case 5:
			if (!tableMode) {
				cout << "������� �����������" << endl << endl;
				break;
			}

			cout << "�������� ����� ��������: 1. �� ����� 2. �� ������" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();

			flag = false;

			if (subnavig == 1) {
				cout << "������� ���� ��� ��������: ";
				
				getline(cin, buffer);

				if (tableMode == 1) {
					flag = removeByKey(tableL, buffer);
				}
				else if (tableMode == 2) {
					flag = removeByKey(tableC, buffer);
				}

				if (flag) {
					cout << "������� � �������� ������ ������" << endl;
				}
				else {
					cout << "������� � �������� ������ �� ������" << endl;
				}
			}
			else if (subnavig == 2) {
				cout << "������� ������ ��� ��������: ";
				getline(cin, buffer);
				
				if (tableMode == 1) {
					flag = removeByData(tableL, buffer);
				}
				else if (tableMode == 2) {
					flag = removeByData(tableC, buffer);
				}

				if (flag) {
					cout << "������� � ��������� ������� ������" << endl;
				}
				else{
					cout << "������� � ��������� ������� �� ������" << endl;
				}
			}
			else {
				cout << "������������ ������" << endl;
			}
			cout << endl;
			break;

		case 6:
			if (tableMode == 1) {
				saveTable(tableL);
				cout << "������� ���������" << endl;
			}
			else if (tableMode == 2) {
				saveTable(tableC);
				cout << "������� ���������" << endl;
			}
			else {
				cout << "������� �����������" << endl;
			}
			cout << endl;
			break;

		case 7:
			cout << "�������� ��� �������: 1. �������� 2. ������" << endl;
			cout << endl << ">";
			cin >> subnavig;
			cin.ignore();

			if (subnavig == 1) {
				tableMode = 1;
				readTable(tableL);
				cout << "������������ hash-�������" << endl;

			}
			else if (subnavig == 2)
			{
				tableMode = 2;
				readTable(tableC);
				cout << "������������ hash-�������" << endl;
			}
			else {
				cout << "������������ ������" << endl;
			}

			cout << endl;
			break;

		case 8:
			if (tableMode == 1) {
				clearTable(tableL);
				cout << "������� ��������" << endl;
			}
			else if (tableMode == 2) {
				clearTable(tableC);
				cout << "������� ��������" << endl;
			}
			else {
				cout << "������� �����������" << endl;
			}
			cout << endl;
			break;
		default:
			break;
		}

	} while (navig != 0);


	return 0;
}