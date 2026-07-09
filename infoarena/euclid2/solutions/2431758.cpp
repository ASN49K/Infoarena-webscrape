#include <iostream>
#include <fstream>
using namespace std;


int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int T, A, B;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    if (!fin.is_open()) {
       cout << "Unable to open the input file."; 
    }
    if (!fout.is_open()) {
        cout << "Unable to open the output file.";
    }
    fin >> T;
    for (int i = 0; i < T; ++i) {
        fin >> A >> B;
        fout << gcd(A, B) << endl;
    }

    return 0;
}