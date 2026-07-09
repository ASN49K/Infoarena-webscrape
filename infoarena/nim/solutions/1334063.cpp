#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    
    int t, n, x, sol;
    
    fin >> t;
    
    for (int i = 1; i <= t; i++) {
        fin >> n;
        for (int j = 1; j <= n; j++) {
            fin >> x;
            if (j == 1) {
                sol = x;
                continue;
            }
            sol = sol ^ x;
        }
        sol == 0 ? fout << "NU\n" : fout << "DA\n";
    }
    
    fin.close();
    fout.close();
    
}