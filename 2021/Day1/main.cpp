#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

//Part 2
int main() {
    vector<int> depths;
    ifstream inFile;
    int largerCount,x,currSum,nextSum;
    
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }
    
    while (inFile >> x) {
        depths.push_back(x);
    }

    //Checks if the sum of element n and the 2 adjacent elements is greater than the sum of element n+1 and two adjacent elements
    for (int i = 0; i < depths.size()-3; i++) {
        currSum = depths[i] + depths[i+1] + depths[i+2];
        nextSum = depths[i+1] + depths[i+2] + depths[i+3];
        if (nextSum > currSum) {
            largerCount++;
        }
    }
    
    inFile.close();
    cout << largerCount << endl; 
    return 0;
}

// Part 1
// int main() {
//     vector<int> depths;
//     ifstream inFile;
//     int largerCount,x;
    
//     inFile.open("input.txt");
//     if (!inFile) {
//         cout << "Unable to open file";
//         exit(1);
//     }
    
//     while (inFile >> x) {
//         depths.push_back(x);
//     }

//     for (int i = 0; i < depths.size()-1; i++) {
//         if (depths[i] < depths[i+1]) {
//             largerCount++;
//         }
//     }
    
//     inFile.close();
//     cout << largerCount << endl; 
//     return 0;
// }