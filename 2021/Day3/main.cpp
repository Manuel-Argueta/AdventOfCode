#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> findRating(vector<string> report, int n, string type);

//Part 2
int main() {
    vector<string> oxyReport, carReport, result;
    ifstream inFile;
    int n, oxyVal, carVal;
    string x, oxygenRating, carbonRating;
    
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }
    
    while (inFile >> x) {
        oxyReport.push_back(x);
        carReport.push_back(x);
        if (n == 0) {
            n = x.length();
        }
    }

    
    oxygenRating = findRating(oxyReport, n, "oxygen")[0];
    carbonRating = findRating(carReport, n, "carbon")[0];

    //Binary to Decimal Conversion
    oxyVal = 0;
    carVal = 0;
    for (int i = 0; i < n; i++) {
        if (oxygenRating[i] == '1') {
            oxyVal += pow(2,(n-1)-(i));
        }
        if (carbonRating[i] == '1') {
            carVal += pow(2,(n-1)-(i));
        }
    }
    
    cout << oxyVal*carVal << endl;

    inFile.close();
    
    return 0;
}

//Returns updated array with the final bit that meets all criterion (passes all filters)
vector<string> findRating(vector<string> report, int n, string type) {
        vector<char> currBits;
        int oneC, zeroC, i, removeC;
        char toFind;
        i = 0;

        //Reduces report size until there is only 1 element left
        while (report.size() != 1 && i < n) {

            //Finding bit with highest frequency in a given position across all bits in report
            for (int j = 0; j < report.size(); j++) {
                currBits.push_back(report[j][i]);
                if (report[j][i] == '1'){
                    oneC++;
                } else {
                    zeroC++;
                }
            }
            
            //checks type of rating to be found to choose toFind (the bit filter)
            if (oneC > zeroC && type == "oxygen") {
                toFind = '1';
            } else if (oneC > zeroC && type == "carbon") {
                toFind = '0';
            } else if (oneC < zeroC && type == "oxygen") {
                toFind = '0';
            } else if (oneC < zeroC && type == "carbon") {
                toFind = '1';
            } else if (oneC == zeroC && type == "oxygen") {
                toFind = '1';
            } else if (oneC == zeroC && type == "carbon") {
                toFind = '0';
            } 

            removeC = 0;
            for (int k = 0; k < currBits.size(); k++) {
                //the current bit in report vector must have the same bit  as the most common one (toFind) in given position
                if (currBits[k] != toFind) {
                    // k-removeC to find new index (in terms of currBit vector) after resizing of report vector
                    report.erase(report.begin() + (k-removeC));
                    removeC++;
                }
            }

            oneC = 0; 
            zeroC = 0;
            removeC = 0;
            currBits.clear();
            i++;
        }

        return report;
}








//Part 1
// int main() {
//     vector<string> report;
//     ifstream inFile;
//     string x,gamma ,epsilon;
//     int n, oneC, zeroC, gammaVal, epsiVal;
//     inFile.open("input.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1);
//     }
    
//     while (inFile >> x) {
//         report.push_back(x);
//         if (n == 0) {
//             n = x.length();
//         }
//     }

//     //Find frequencies of 1 and 0 at given position in a bit number
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < report.size(); j++) {
//             if (report[j][i] == '1'){
//                 oneC++;
//             } else {
//                 zeroC++;
//             }
//         }
//         //Add number with most frequency to gamma, least frequency to epsilon
//         if (oneC > zeroC) {
//             gamma.push_back('1');
//             epsilon.push_back('0');
//         } else {
//             gamma.push_back('0');
//             epsilon.push_back('1');
//         }
//         oneC = 0; 
//         zeroC = 0;
//     }

//     //Binary to Decimal Conversion
//     gammaVal = 0;
//     epsiVal = 0;
//     for (int i = 0; i < n; i++) {
//         if (gamma[i] == '1') {
//             gammaVal += pow(2,(n-1)-(i));
//         } else {
//             epsiVal += pow(2,(n-1)-(i));
//         }
//     }



//     inFile.close();
//     cout << gamma << " " << epsilon << endl; 
//     cout << gammaVal << " " << epsiVal << endl; 
//     cout << gammaVal*epsiVal << endl; 
//     return 0;
// }