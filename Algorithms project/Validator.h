#ifndef __VALIDATOR_H
#define __VALIDATOR_H
#pragma warning (diable: 4996)

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

class Validator
{
private:
	const char* m_fileName;

public:
	Validator(const char * i_fileName);
	~Validator();
	bool checkWholePageLogicly();
	bool checkWholePageSpellCorrectness();
	bool checkNegativeCf();
	bool checkNumOfAdjes();
	ifstream  checkFirstFourRows();
	bool checkTheRestOfTheFile(ifstream i_inFile);

};









#endif