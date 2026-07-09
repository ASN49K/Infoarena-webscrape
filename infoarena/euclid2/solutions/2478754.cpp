#include <iostream>

using namespace std;

int main() {
    int nr1, nr2, rest;

    cout << "Introduceti cele doua numere: " << endl;

    cin >> nr1 >> nr2;
    while (nr2 != 0){
        rest = nr1 % nr2;
        nr1 = nr2;
        nr2 = rest;
    }

    
    cout << "Cel mai mare divizor comun este: " << nr1;
    return 0;
}