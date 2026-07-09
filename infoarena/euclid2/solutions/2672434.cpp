// probleme noi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int a, b, c, d, e;
    cin >> a;
    if (a <= 100000 && a > 1) 
        for (int i = 1; i <= a; i++) {
            cin >> c >> e;
            while (e != 0) {
                d = c % e;
                c == e;
                e == d;
                cout << c "\n";
            }
            fin.close();
            fout.close();
        }
    return 0;
}

    


