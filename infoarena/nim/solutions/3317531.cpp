#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

// int LONG = 1000 * 1000 * 1000 + 7;
int main(){
    int t;
    fin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        fin >> n;
        int val = 0;
        for (int j = 0; j < n; ++j) {
            int nr;
            fin >> nr;
            val = val ^ nr; //xor
        }
        if (val) {
            fout << "DA\n";
        } else {
            fout << "NU\n";
        }
    }
    
    return 0;
}