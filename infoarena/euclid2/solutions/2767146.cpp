#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int euclid(int number1, int number2) {

    if (number1 == 0) {
        return number2;
    } else {
        return euclid(number2 % number1, number1);
    }
}

int main(void) {

    int n;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int number1, number2;
        fin >> number1 >> number2;
        fout << euclid(number1, number2);
        fout << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
