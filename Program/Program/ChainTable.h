#pragma once

#include <string>

struct NodeChain
{
	std::string key = "";
	std::string dat = "";
	NodeChain* ptrNext = nullptr;
	NodeChain* ptrPrev = nullptr;
};

struct HashTableChain
{
	NodeChain* table[M];
	HashTableChain() {
		for (int i = 0; i < M; ++i) {
			table[i] = nullptr;
		}
	}
};