#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int number, int secondNumber);

int main() {
    int length;
    fin>>length;
    for (int step = 0; step < length; ++step) {
        int firstNumber, secondNumber;
        fin>>firstNumber>>secondNumber;
        fout<<cmmdc(firstNumber,secondNumber);
    }
    fin.close();
    fout.close();
    return 0;
}

int cmmdc(int number, int secondNumber) {
    if(secondNumber == 0)
        return number;
    cmmdc(secondNumber,number%secondNumber);
}