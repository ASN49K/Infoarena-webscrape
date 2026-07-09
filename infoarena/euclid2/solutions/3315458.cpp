#include <iostream>
#include<fstream>
using namespace std;
int T, a, b, r,res;
int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> T;
    for (int i = 0; i < T; i++) {
        fin >> a;
        fin >> b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        res = a;
        fout << res << endl;
    }
    fin.close();
    fout.close();

    return 0;
}