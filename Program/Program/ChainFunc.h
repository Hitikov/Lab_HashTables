#pragma once

#include <fstream>

#include "CommonFunc.h"
#include "ChainTable.h"

bool add(HashTableChain& table, std::string key, std::string custData) {
	NodeChain* newNode = new NodeChain;
	newNode->key = key;
	newNode->dat = custData;

	int hash = getHash(key);

	if (table.table[hash] == nullptr) {
		table.table[hash] = newNode;
		return true;
	}
	else {
		NodeChain* current = table.table[hash];
		while (current->ptrNext != nullptr) {
			current = current->ptrNext;
			collisionCount++;
		}
		current->ptrNext = newNode;
		newNode->ptrPrev = current;
		return true;
	}
}

void makeHum(HashTableChain& table) {
	std::string dat = makeDate();
	std::string name = makeName() + '|' + dat + '|' + makePass();
	add(table, dat, name);
}

bool removeByKey(HashTableChain& table, std::string key) {
	int hash = getHash(key);
	NodeChain* current = table.table[hash];
	while (current != nullptr) {
		if (current->key == key) {
			if (current->ptrPrev != nullptr) {
				current->ptrPrev->ptrNext = current->ptrNext;
			}
			else {
				table.table[hash] = current->ptrNext;
			}
			if (current->ptrNext != nullptr) {
				current->ptrNext->ptrPrev = current->ptrPrev;
			}
			delete current;
			return true;
		}
		current = current->ptrNext;
	}
	return false;
}

bool removeByData(HashTableChain& table, std::string dat) {
	for (int i = 0; i < M; i++)
	{
		NodeChain* current = table.table[i];
		while (current != nullptr) {
			if (current->dat == dat) {
				if (current->ptrPrev != nullptr) {
					current->ptrPrev->ptrNext = current->ptrNext;
				}
				else {
					table.table[i] = current->ptrNext;
				}
				if (current->ptrNext != nullptr) {
					current->ptrNext->ptrPrev = current->ptrPrev;
				}
				delete current;
				return true;
			}
			current = current->ptrNext;
		}
	}
	return false;
}


NodeChain* get(HashTableChain& table, std::string key) {
	int hash = getHash(key);
	NodeChain* current = table.table[hash];
	while (current != nullptr)
	{
		if (current->key == key) {
			return current;
		}
		current = current->ptrNext;
	}
	return nullptr;
}

void printTable(HashTableChain& table) {
	for (int i = 0; i < M; i++) {
		NodeChain* current = table.table[i];
		while (current != nullptr)
		{
			std::cout << current->key << " [" << current->dat << "]" << std::endl;
			current = current->ptrNext;
		}
	}
	std::cout << std::endl;
}

void saveTable(HashTableChain& table) {
	std::ofstream out;
	out.open("File.txt");
	for (int i = 0; i < M; i++) {
		NodeChain* current = table.table[i];
		while (current != nullptr)
		{
			out << current->key << std::endl << current->dat << std::endl;
			current = current->ptrNext;
		}
	}
	out.close();
}

void clearTable(HashTableChain& table) {
	collisionCount = 0;
	for (int i = 0; i < M; i++) {
		NodeChain* current = table.table[i];
		while (current != nullptr)
		{
			table.table[i] = current->ptrNext;
			delete current;
			current = table.table[i];
		}
	}
}

void readTable(HashTableChain& table) {
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