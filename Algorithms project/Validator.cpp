#include "Validator.h"
#pragma warning(disable : 4996)

Validator::Validator(char* i_fileName)
{
     m_fileName = i_fileName;
}

Validator::~Validator()
{

}

bool Validator::checkWholePageLogicly()
{
     bool answer = true;
     if (checkNegativeCf())
     {
          cout << "there is a Negative Cf in the input Graph. Error\n";
          answer = false;
     }
     else if (checkNumOfAdjes)
     {
          cout << " there is a wrong number of adjes. Error\n";
          answer = false;
          
     }
  
     return answer;
}

bool Validator::checkNegativeCf()
{
     return false;
}

bool Validator::checkNumOfAdjes()
{
     return false;
}
