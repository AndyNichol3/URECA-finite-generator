#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "type.h"

// recursive funtion to generate all possible combinations
void FindCombinations(int inputArray[], int combinationArray[], int start,
                      int end, int index, int r, fstream &inFile) {

  if (index == r) {
    //  cout << "combination: ";
    for (int i = 0; i < r; i++) {

      //  cout << combinationArray[i] << " ";

      // write to file
      inFile << combinationArray[i] << " ";

      // write to file instead of cout
      // then reaccess from main
    }
    //  cout << endl;
    inFile << endl;
    return;
  }

  for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
    combinationArray[index] = inputArray[i];
    FindCombinations(inputArray, combinationArray, i + 1, end, index + 1, r,
                     inFile);
  }
}

void clearTextFile() {
  fstream inFile;
  // clear contents and open
  inFile.open("combo.txt", ofstream::out | ofstream::trunc);

  inFile.close();
}
void printVector(data GraphData, vector<int> comboVector) {
  // size adjusted to starting at 1 not 0
  for (int i = 0; i < comboVector.size(); i++) {
    cout << comboVector[i] + 1 << " ";
  }
  cout << endl;
}
