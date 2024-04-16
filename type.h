#ifndef TYPE_H
#define TYPE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 50;

// this current is the petersens grph representation
class data {
public:
  int Graph[MAX_SIZE][MAX_SIZE];
  int graphI = 0;
  int graphJ = 0;
  int graphNodes = 0;
  int totalCombos = 0;

  data() {
    cout << "constructor called" << endl;  
    fstream inFile;
    inFile.open("input.txt");

    inFile >> graphI >> graphJ;


    for (int i = 0; i < graphI; i++) {
      for (int j = 0; j < graphJ; j++) {
        inFile >> Graph[i][j];
  
      }
    }

    inFile.close();
    graphNodes = graphI; 
  }
};

void FindCombinations(int inputArray[], int combinationArray[], int start,
                      int end, int index, int r, fstream &inFile);

void clearTextFile();
void printVector(data GraphData, vector<int> comboVector);

#endif