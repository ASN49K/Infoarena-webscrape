#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin >> n;
    while (n--) {
        int firstNumber, secondNumber;
        fin >> firstNumber >> secondNumber;
        fout << cmmdc(firstNumber, secondNumber) << '\n';
    }
    return 0;
}
