#include <iostream>
#include <algorithm>
#include <fstream>

class Solution {
public:
    int gcd(int firstNumber, int secondNumber) {
        if (firstNumber < secondNumber) std::swap(firstNumber, secondNumber);
        int temp = 0;

        while (secondNumber != 0) {
            temp = firstNumber;
            firstNumber = secondNumber;
            secondNumber = temp % secondNumber;
        }

        return firstNumber;
    }
};


int main() {
    Solution s;
    std::ofstream oFile;
    std::ifstream iFile;
    oFile.open("euclid2.out");
    iFile.open("euclid2.in");

    int numberOfPairs = 0;
    iFile >> numberOfPairs;
    
    int numA = 0;
    int numB = 0;
    for (int i = 1; i <= numberOfPairs; i++) {
        iFile >> numA >> numB;
        oFile << s.gcd(numA, numB) << "\n";
    }

    oFile.close();
    iFile.close();
    return 0;
}