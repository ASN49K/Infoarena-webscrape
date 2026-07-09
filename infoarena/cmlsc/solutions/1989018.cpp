#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inFile("cmlsc.in");
    std::ofstream outFile("cmlsc.out");

    int nA, nB;

    inFile >> nA >> nB;

    int *arrA, *arrB;
    int **arrC;

    arrA = new int[nA];
    arrB = new int[nB];
    arrC = new int*[nA + 1];

    for (int i = 0; i <= nA; i++) {
        arrC[i] = new int[nB + 1];
    }

    for (int i = 0; i < nA; i++) {
        inFile >> arrA[i];
    }

    for (int i = 0; i < nB; i++) {
        inFile >> arrB[i];
    }

    for (int i = 0; i <= nA; i++) {
        for (int j = 0; j <= nB; j++) {
            arrC[i][j] = 0;
        }
    }

    for (int i = 1; i <= nA; i++) {
        for (int j = 1; j <= nB; j++) {
            if (arrA[i - 1] == arrB[j - 1]) {
                arrC[i][j] = arrC[i - 1][j - 1] + 1;
            } else {
                arrC[i][j] = std::max(arrC[i - 1][j], arrC[i][j - i]);
            }
        }
    }

    std::vector<int> myVect;

    for (int i = nA, j = nB; i > 0 && j > 0; ) {
        if (arrA[i - 1] == arrB[j - 1]) {
            myVect.push_back(arrA[i - 1]);
        } else if (arrC[i - 1][j] > arrC[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    outFile << myVect.size() << std::endl;
    for (auto it = myVect.rbegin(); it != myVect.rend(); it++) {
        outFile << *it << ' ';
    }

    delete[] arrA;
    delete[] arrB;

    for (int i = 0; i <= nA; i++) {
        delete[] arrC[i];
    }
    delete[] arrC;

    return 0;
}
