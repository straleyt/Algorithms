//Tegan Straley
//CSCI 3412 
//Problem set 2


#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <iterator>
#include <algorithm>

using namespace std;

//Creation of global variables
int uniqueNum = 0;
int assignments = 0;
int comparisions = 0;


struct shakeWord
{
     string word;
     int times;

     bool operator < (const shakeWord& str) const
     {
          return (word < str.word);
     }
};

struct BSTNode
{
     shakeWord data;
     BSTNode* left;
     BSTNode* right;
};

void printVector(vector<shakeWord> shakeVector)
{
     for (size_t j = 0; j < shakeVector.size(); j++)
     {
          cout << shakeVector[j].times << shakeVector[j].word << endl;
     }
}



BSTNode* GetNewNode(shakeWord data)
{
     BSTNode* newNode = new BSTNode();
     newNode->data.word = data.word;
     newNode->data.times = data.times;
     newNode->left = newNode->right = NULL;
     assignments += 1;

     return newNode;
}

BSTNode* Insert(BSTNode* root, shakeWord data)
{
     if (root == NULL) //tree starts empty!
     {
          root = GetNewNode(data);
          return root;
     }
     else if (data.word <= root->data.word){
          root->left = Insert(root->left, data);
     }
     else
     {
          root->right = Insert(root->right, data);
     }
     return root;
}


bool Search(BSTNode* root, string data)
{
     if (root == NULL)
     {
          comparisions += 1;
          return false;
     }
     else if (root->data.word == data)
     {
          root->data.times += 1;
          assignments += 1;
          comparisions += 1;
          return true;
     }

     else if (data <= root->data.word)
     {
          comparisions += 1;
          return Search(root->left, data);
     }
     else
     {
          comparisions += 1;
          return Search(root->right, data);
     }
}

int main()
{

     string tempWord;

     BSTNode* root = NULL; //tree starts empty

     //open textfile
     ifstream infile("wordlist.txt");

     if (infile)
     {
          while (!infile.eof())
          {
               //cout << "in  while.." << endl;
               getline(infile, tempWord);
               for (size_t i = 0; i < tempWord.length(); i++) //Making the word lowercase
               {
                    tempWord[i] = tolower(tempWord[i]);
               }

               if (isalpha(tempWord[0]))
               {
                    shakeWord tempShake;
                    tempShake.word = tempWord;
                    tempShake.times = 1;
                    if (Search(root, tempWord) == false)
                    {
                         uniqueNum += 1;
                         root = Insert(root, tempShake);
                    }

                  
               }//End of if
          }//end of while

          infile.close();               //Vector creation complete


          cout << "Number of unique words: " << uniqueNum << endl;
          cout << "Number of assignments: " << assignments << endl;
          cout << "Number of comparisions: " << comparisions << endl << endl;

     }

     return 0;
}
