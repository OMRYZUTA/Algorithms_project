#ifndef __VALIDATOR_H
#define __VALIDATOR_H
#pragma warning (diable: 4996)

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include "Graph.h"

using namespace std;

class Validator
{
private:
	const char* m_fileName;

public:
	Validator(const char * i_fileName);
	virtual	~Validator();
	void checkWholePageLogicly(); // checking if the graph is simple, if the numbers are reasonable
	void checkWholePageSpellCorrectness();// checking that the chars inserted are only numeric, in the right order


};









#endif