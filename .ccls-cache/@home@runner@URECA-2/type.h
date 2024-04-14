#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <fstream> 
#include <string> 

using namespace std; 

// this current is the petersens grph representation
class data{
public:
const int Graph[10][10] = {

    {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
};
int graphI = 10;
int graphJ = 10; 
int graphNodes = 10; 
int totalCombos = 0; 


}; 



void FindCombinations(int inputArray[], int combinationArray[], int start,
int end, int index, int r, fstream &inFile);

void clearTextFile(); 

#endif