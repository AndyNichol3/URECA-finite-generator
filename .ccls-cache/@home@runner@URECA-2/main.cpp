#include "type.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  clearTextFile();
  data GraphData;

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

    fstream read;
    read.open("combo.txt");
    while (!read.eof()) {
      // topOfWhileLoop:

      vector<int> comboVector;
      string comboString;
      string storage = "";
      getline(read, comboString, '\n');
      int index = 0;

      // put into vector
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

      // --------------
      //  display vector
      // --------------
      /*

      for (int i = 0; i < comboVector.size(); i++) {
        cout << comboVector[i] << " ";
        GraphData.totalCombos++;
      }
      cout << endl;
*/
      // do work down here

      // generate neighborhoods

      // should be graphNode,Size;
      vector<int> Array_neighborhood[10];

      for (int detectorITT = 0; detectorITT < comboVector.size();
           detectorITT++) {
        int detector = comboVector[detectorITT];

        // here we are itterating through all of the detectors.
        // add decctors to the nieghborhoods
        /*
        for(int i = 0; i < GraphData.graphI; i++){
          if(i == detector){
            for(int j = 0; j < GraphData.graphJ; j++){
              if(GraphData.Graph[i][j] == 1){

              }
            }
          }
        }
        */

        // cout << "detector: " << detector << endl;

        // as of here we have the number of the node that should be a detector
        // access row of detector
        // if edge exists, add detector to the neighborhood vector

        /// DOES NOT INCLUDE THE DETECTOR ITSELF SO OLD HERE
        // CHANGE HERE FOR IC
        for (int j = 0; j < GraphData.graphJ; j++) {
          if (GraphData.Graph[detector][j] == 1) {
            Array_neighborhood[j].push_back(detector);
          }
        }
      }

      // check for valid solution
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

      // cout << "no empty" << endl;

      // for 1-10 if array .size empty, fail solution and break
      // then sort and check for repitition

      /*
            int iTally = 0;
            bool solution = true;
            for(auto i : Array_neighborhood){
              // i = vector
              int jTally = -1;
              if(!solution){
                break;
              }
             // cout << "Neighborhood " << c << endl;
              for(auto j : Array_neighborhood){
                jTally ++;
                if(i == j){
                  cout << "VECTOR MATCH" << endl ;

                }
                if(!solution){
                  break;
                }
                if (iTally == jTally){
                  continue;
                }

                // compare the j and i
                // if any are the same, not valid, break
                if(i.size() != j.size()){
                  continue;
                }
                // if they are the same size, check if they are the same

                // we have equal sizes,
                // now we need to

                int tally = 0;

                for(int compare = 0; compare < i.size(); compare++){
                  if(i[compare] != j[compare]){
                    break;
                    continue;
                  } else{
                    tally ++;
                  }

                }

                if(tally == i.size()){
                  // you have a match
                  // not a solution
                  continue;
                  solution = false;
                }



              }


              iTally++;

              //
              for(int j = 0; j < i.size(); j++){
                cout << i[j] << " ";
              }
              cout << endl;
              //
            }
      */
      bool solution = true;

      int iTally = 0;
      for (auto i : Array_neighborhood) {
        if (!solution) {
          break;
        }

        int jTally = 0;
        for (auto j : Array_neighborhood) {
          if (iTally == jTally) {
            jTally++;
            continue;
          }
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

      if (solution) {
        for (int i = 0; i < comboVector.size(); i++) {
          cout << comboVector[i] << " ";
          GraphData.totalCombos++;
        }
        cout << endl;
      }

      // if valid, print and add to tally
      // if not, dont and add to tally
    }
  }

  cout << GraphData.totalCombos << endl;
}
