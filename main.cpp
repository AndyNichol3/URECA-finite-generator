#include "type.h"
// todo list
// user input validation for METHOD

int main() {

  int METHOD;
  // if method == 0; OLD
  // if methof == 1; IC

  cout << "WHAT IS OUR WORKING METHOD?? 0 FOR OLD, 1 FOR IC: " << endl;
  cin >> METHOD;

  // clear txt file for safe keeping
  clearTextFile();
  data GraphData;

  // itterate through the number of nodes in the graph
  // this gives us all possible solutions
  for (int r = 0; r < GraphData.graphNodes; r++) {

    clearTextFile();

    // open file
    fstream inFile;
    inFile.open("combo.txt");

    // create variables
    int n = GraphData.graphNodes;
    int currentCombo[r];
    int sampleCombo[n];
    for (int i = 0; i < n; i++) {
      sampleCombo[i] = i;
    }

    // generate the combonations in the text file
    FindCombinations(sampleCombo, currentCombo, 0, n - 1, 0, r, inFile);

    // close write file
    inFile.close();

    // open the read file to reaccess data
    fstream read;
    read.open("combo.txt");

    // gather info from the txt file
    while (!read.eof()) {

      // define variables
      vector<int> comboVector;
      string comboString;
      string storage = "";
      int index = 0;

      // get the first row
      getline(read, comboString, '\n');

      // put info into vector
      for (int i = 0; i < comboString.length(); i++) {
        if (comboString[i] == ' ') {
          // cout << "storage = " << storage << endl;
          // the correct code
          comboVector.push_back(stoi(storage));

          storage = "";
          index++;
          continue;
        }
        storage += comboString[i];
      }

      // generate neighborhoods

      // neighborhood data structure
      // an array of vectors. the vector contains the index of the detectors
      vector<int> Array_neighborhood[10];

      // generate the neighborhoods
      // cout << "ADDING " << endl;
      for (int detectorITT = 0; detectorITT < comboVector.size();
           detectorITT++) {

        int detector = comboVector[detectorITT];
        ///  cout << "\nDECECTOR : " << detector;
        //   cout << "ADDED TO: ";

        /// DOES NOT INCLUDE THE DETECTOR ITSELF SO OLD HERE
        // CHANGE HERE FOR IC
        if (METHOD == 1) {
          Array_neighborhood[detector].push_back(detector);
          //     cout << detector << " ";
        }
        for (int j = 0; j < GraphData.graphJ; j++) {
          // for IC implementation

          if (GraphData.Graph[detector][j] == 1) {
            Array_neighborhood[j].push_back(detector);
            //    cout << j << " ";
          }
        }
      }

      // check for valid solution
      // sort the vectors, if any are empty
      // solution is invalid
      bool ValidSolution = true;
      for (auto i : Array_neighborhood) {
        sort(i.begin(), i.end());
        if (i.size() == 0) {
          ValidSolution = false;
          break;
        }
      }
      if (!ValidSolution) {
        continue;
      }

      // check for valid solution
      // check every array against the other arrays
      bool solution = true;
      int iTally = 0;
      for (auto i : Array_neighborhood) {
        if (!solution) {
          break;
        }

        int jTally = 0;
        for (auto j : Array_neighborhood) {
          // dont compare against its self
          if (iTally == jTally) {
            jTally++;
            continue;
          }
          // compare
          if (i == j) {
            solution = false;
          }
          jTally++;
          if (!solution) {
            break;
          }
        }

        iTally++;
      }

      // if the solution is valid, print
      if (solution) {
        printVector(GraphData, comboVector);
        GraphData.totalCombos++; // in the class
      }
    }
  }
  // print the number of valid solutions
  cout << GraphData.totalCombos << endl;
}
