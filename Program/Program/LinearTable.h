#pragma once

#include <string>

struct NodeLinear
{
	std::string key = "";
	std::string dat = "";
};

struct HashTableLinear
{
	NodeLinear* table[M];
	HashTableLinear() {
		for (int i = 0; i < M; ++i) {
			table[i] = nullptr;
		}
	}
};