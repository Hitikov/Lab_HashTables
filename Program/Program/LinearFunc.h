#pragma once

#include <fstream>

#include "CommonFunc.h"
#include "LinearTable.h"

bool add(HashTableLinear& table, std::string key, std::string custData) {
	NodeLinear* newNode = new NodeLinear;
	newNode->key = key;
	newNode->dat = custData;

	int hash = getHash(key);

	if (table.table[hash] == nullptr) {
		table.table[hash] = newNode;
		return true;
	}
	else {
		int index = 0;
		for (; table.table[(index + hash) % M] != nullptr && index < M; ++index);
		collisionCount += index;

		if (index != M) {
			table.table[(index + hash) % M] = newNode;
			return true;
		}
		else {
			return false;
		}

	}
}

void makeHum(HashTableLinear& table) {
	std::string dat = makeDate();
	std::string name = makeName() + '|' + dat + '|' + makePass();
	add(table, dat, name);
}

bool removeByKey(HashTableLinear& table, std::string key) {
	int hash = getHash(key);
	int index = 0;
	bool isFind = false;
	while (!isFind && index < M) {
		if (table.table[(index + hash) % M] != nullptr) {
			if (table.table[(index + hash) % M]->key != key) {
				++index;
			}
			else {
				isFind = true;
			}
		}
		else {
			++index;
		}
	}

	if (index != M) {
		delete table.table[(index + hash) % M];
		table.table[(index + hash) % M] = nullptr;
		return true;
	}
	else {
		return false;
	}
}

bool removeByData(HashTableLinear& table, std::string dat) {
	int index = 0;
	bool isFind = false;
	while (!isFind && index < M) {
		if (table.table[index] != nullptr) {
			if (table.table[index]->dat != dat) {
				++index;
			}
			else {
				isFind = true;
			}
		}
		else {
			++index;
		}
	}

	if (index != M) {
		delete table.table[(index) % M];
		table.table[(index) % M] = nullptr;
		return true;
	}
	else {
		return false;
	}
}

NodeLinear* get(HashTableLinear& table, std::string key) {
	int hash = getHash(key);
	int index = 0;
	bool isFind = false;
	while (!isFind && index < M) {
		if (table.table[(index + hash) % M] != nullptr) {
			if (table.table[(index + hash) % M]->key != key) {
				++index;
			}
			else {
				isFind = true;
			}
		}
		else {
			++index;
		}
	}

	if (index != M) {
		return table.table[(index + hash) % M];
	}
	else {
		return nullptr;
	}
}

void printTable(HashTableLinear& table) {
	for (int i = 0; i < M; i++) {
		if (table.table[i] != nullptr) {
			NodeLinear* current = table.table[i];
			std::cout << current->key << " [" << current->dat << "]" << std::endl;
		}
	}
	std::cout << std::endl;
}

void saveTable(HashTableLinear& table) {
	std::ofstream out;
	out.open("File.txt");
	for (int i = 0; i < M; i++) {
		if (table.table[i] != nullptr) {
			NodeLinear* current = table.table[i];
			out << current->key << std::endl << current->dat << std::endl;
		}
	}
	out.close();
}

void clearTable(HashTableLinear& table) {
	collisionCount = 0;
	for (int i = 0; i < M; i++) {
		NodeLinear* current = table.table[i];
		if (table.table[i] != nullptr) {
			delete current;
			table.table[i] = nullptr;
		}
	}
}

void readTable(HashTableLinear& table) {
	clearTable(table);
	std::ifstream in;
	in.open("File.txt");
	while (!in.eof()) {
		std::string key;
		getline(in, key);
		std::string data;
		getline(in, data);
		if (key != "" && data != "") {
			add(table, key, data);
		}
	}
	in.close();
}