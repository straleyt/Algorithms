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

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashClass
{

private:
     static const unsigned long tableSize = 200000;
     struct item
     {
          string word;
          int times;
          item* next;
     };

     item* HashTable[tableSize];

public:
     unsigned long HashFunction(string key);
     hashClass();
     void AddItem(string word, int times);
     int NumberOfItemsInIndex(long index);
     void PrintTable();
     long uniqueNum;
     long assignments;
     long comparisions;
};
#endif // endif HASH_H