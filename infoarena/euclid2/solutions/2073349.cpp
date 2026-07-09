#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

unsigned long int cmmdc(int a, int b) {
    while (b) {
        int aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

int main()
{
    unsigned long int t,a,b;
    fin.open("euclid2.in");
    fout.open("euclid2.out");

    fin >> t;
    for (int i = 0; i < t; i++) {
        fin >> a;
        fin >> b;
        fout << cmmdc(a, b) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
