#pragma once

#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

const double A = M_PI_4;

double mod1(double k) {
	int intValue = static_cast<int>(k);
	return k - intValue;
}

int getHash(double k) {
	return static_cast<int> (M * mod1(A * k));
}

int getHash(std::string line) {
	int hash = 0;
	for (int i = 0; i < line.size(); ++i) {
		hash += static_cast<int>(abs(line[i]) * M_LN10 + pow(line[i], 2) * M_PI_2);
	}

	return getHash(abs(hash));
}

std::string fName[] = {
	"fA", "fB", "fC", "fD", "fE", "fF", "fG", "fH", "fI", "fJ"
};

std::string iName[] = {
	"iA", "iB", "iC", "iD", "iE", "iF", "iG", "iH", "iI", "iJ"
};

std::string oName[] = {
	"oA", "oB", "oC", "oD", "oE", "oF", "oG", "oH", "oI", "oJ"
};

std::string makeName() {
	return fName[rand() % 10] + ' ' + iName[rand() % 10] + ' ' + oName[rand() % 10];
}

std::string correctStr(int n, int size) {
	std::string strn = std::to_string(n);
	while (strn.size() < size) {
		strn = '0' + strn;
	}
	while (strn.size() > size) {
		strn.erase(0, 1);
	}
	return strn;
}

std::string makeDate() {
	return correctStr(rand() % 28 + 1, 2) + '/' + correctStr(rand() % 12 + 1, 2) + '/' + std::to_string(rand() % 74 + 1950);
}

std::string makePass() {
	return correctStr(rand() % 10000, 4) + correctStr(rand() % 1000000 * 100 + rand(), 6);
}

