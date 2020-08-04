#include "Validator.h"
#pragma warning(disable : 4996)
// opening file called "input.txt"
Validator::Validator(const char* i_fileName)
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
     else if (checkNumOfAdjes())
     {
          cout << " there is a wrong number of adjes. Error\n";
          answer = false;
          
     }
  
     return answer;
}

bool Validator::checkWholePageSpellCorrectness()
{
     bool answer = true;
     // checking spell in the first 4 inputs
     ifstream inFile(m_fileName); // opening file called "input.txt"
     char charChecker1;
     bool isNewLine = true;

     int numCounter = 0;
     bool isTabOrSpace = false;
     bool isNum = false;
     inFile >> std::noskipws;
     while (inFile >> charChecker1 && isNewLine )
     {
          if (charChecker1 < '0' || charChecker1>'9')
          {
               if (charChecker1 == '\n')
               {
                    isNewLine = true;
                    isTabOrSpace = false;
                    if (isNum)
                    {
                         numCounter++;
                         isNum = false;
                    }
               }
               else if (charChecker1 == ' ' || charChecker1 == '\t')
               {

                    if (isNum)
                    {
                         isTabOrSpace = true;
                         numCounter++;
                         isNum = false;
                    }
               }

               else
               {
                    isNewLine = false;
                    cout << "Error " << charChecker1 << " is not numeric or whitespace input entered" << endl;
                    exit(1);
               }
          }
          else if (!isNum)
          {
               if (isTabOrSpace)
               {
                    cout << "Error! there isn't new line between first 4 parameters";
                    exit(1);
               }
               isNum = true;
               isTabOrSpace = false;
          }
          if (numCounter >= 4)
          {
               break;
          }
     }
     if (numCounter < 4)
     {
          cout << "Error! there is less then 4 numbers in an input row" << endl;
          exit(1);
     }
     int numCounterInLine = 0;
     while (inFile >> charChecker1 && isNewLine && numCounterInLine < 4)
          {
          cout << charChecker1;
               if (charChecker1 < '0' || charChecker1>'9')
               {
                    if (charChecker1 == '\n')
                    {
                         isNewLine = true;
                         isTabOrSpace = false;
                         if (isNum)
                         {
                              numCounterInLine++;
                             
                              
                              
                         }
                         if (numCounterInLine < 3 && numCounterInLine != 0)
                         {
                              cout << "Error! only " << numCounterInLine << " numbers in line";
                              exit(1);
                         }
                         isNum = false;
                         numCounterInLine = 0;
                    }
                    else if (charChecker1 == ' ' || charChecker1 == '\t')
                    {

                         if (isNum)
                         {
                              isTabOrSpace = true;
                              numCounterInLine++;
                              isNum = false;
                         }
                    }

                    else
                    {
                         isNewLine = false;
                         cout << "Error " << charChecker1 << " is not numeric or whitespace input entered" << endl;
                         exit(1);
                    }
               }
               else if (!isNum)
               {
            
                    isNum = true;
                    isTabOrSpace = false;
               }
          }
     if (numCounterInLine > 3)
     {
          cout << "Error! there is more then 3 numbers in input" << endl;
          exit(1);
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



