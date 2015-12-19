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


hashClass::hashClass()
{
     for (unsigned long i = 0; i < tableSize; i++)
     {
          HashTable[i] = new item;
          HashTable[i]->word = "";
          HashTable[i]->times = 0;
          HashTable[i]->next = NULL;
     }
}


unsigned long hashClass::HashFunction(string key)
{
    // cout << "in hashFunction\n" << endl;
     unsigned long hash = 5381;

     for (size_t i = 0; i < key.length();i++)
     {
          hash = ((hash << 5) + hash) + (int)key[i];
     }
     hash = hash % tableSize;
    // cout << "at end hashFunction\n" << endl;
     return hash;
}

void hashClass::AddItem(string word, int times)
{
  //   cout << "in add item\n" << endl;
     long index = HashFunction(word);
   //  cout << "found hash bucket number\n" << index << endl;

     if (HashTable[index]->word == "")
     {
     //     cout << "in if bucket empty\n" << endl;
          HashTable[index]->word = word;
          HashTable[index]->times = times;
          uniqueNum += 1;
          comparisions += 1;
          assignments += 1;
     }
     else if (HashTable[index]->word == word)
     {
     //     cout << "in if word is word\n" << endl;
          HashTable[index]->times += 1;
          comparisions += 1;
     }
     else
     {
 
          bool found = false;

          item* Ptr = HashTable[index];
          item* n = new item;
          n->word = word;
          n->times = times;
          n->next = NULL;
          while (Ptr->next != NULL && found != true)
          {
               comparisions += 1;
               if ((Ptr->next)->word == word)
               {
                    (Ptr->next)->times += 1;
                    found = true;                    
               }
               Ptr = Ptr->next;
          }

          if (found == false)
          {
               uniqueNum += 1;
               assignments += 1;

               Ptr->next = n;
          }
         
     }
}

int hashClass::NumberOfItemsInIndex(long index)
{
     int count = 0;
     if (HashTable[index]->word == "")
     {
          return count;
     }
     else
     {
          count++;
          item* Ptr = HashTable[index];
          while (Ptr->next != NULL)
          {
               count++;
               Ptr = Ptr->next;
          }
     }
     return count;
}

void hashClass::PrintTable()
{
     int number;
     for (unsigned long i = 0; i < tableSize; i++)
     {
          if (HashTable[i]->word != "")
          {
               number = NumberOfItemsInIndex(i);
               cout << "------------------------------------\n";
               cout << "index : " << i << endl;
               cout << HashTable[i]->word << endl;
               cout << "Times: " << HashTable[i]->times << endl;
               cout << "# of Items in bucket: " << number << endl;
               if (number != 1)
               {
                    item * ifPtr = HashTable[i]->next;
                    for (int k = 0; k < number-1; k++)
                    {
                         cout << (ifPtr)->word << endl;
                         ifPtr = ifPtr->next;
                    }
               }
               cout << "------------------------------------\n";
          }

     }
}