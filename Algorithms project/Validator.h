#ifndef __VALIDATOR_H
#define __VALIDATOR_H
#pragma warning (diable: 4996)

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>



using namespace std;

class Validator
{
private:
	char* m_fileName;
public:
	Validator(char * i_fileName);
	~Validator();
	bool checkWholePageLogicly();
	bool checkNegativeCf();
	bool checkNumOfAdjes();

};









#endif