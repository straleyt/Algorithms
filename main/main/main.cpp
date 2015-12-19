//Tegan Straley
//CSCI 3412 
//Problem set 2


#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <functional>
#include "hash.h"

using namespace std;


int main()
{
     string tempWord;
     hashClass hashObj;

     long howMany = 0;
     hashObj.uniqueNum = 0;
     hashObj.assignments = 0;
     hashObj.comparisions = 0;
     //open textfile
     ifstream infile("wordlist.txt");

     if (infile)
     {
          while (!infile.eof())
          {

          //     cout << "in  while.." << endl;
               getline(infile, tempWord);

               for (size_t i = 0; i < tempWord.length(); i++) //Making the word lowercase
               {
                    tempWord[i] = tolower(tempWord[i]);
               }
               
               if (isalpha(tempWord[0]))
               {
                    int times = 1;
                    hashObj.AddItem(tempWord, times);   
                    howMany += 1;
               }//End of if
          }//end of while

          infile.close();               //Vector creation complete

          hashObj.PrintTable();

          cout << "Number of unique words: " << hashObj.uniqueNum << endl;
          cout << "Number of assignments: " << hashObj.assignments << endl;
          cout << "Number of comparisions: " << hashObj.comparisions << endl << endl;
          cout << "How many : " << howMany << endl;
     }

     return 0;
}

