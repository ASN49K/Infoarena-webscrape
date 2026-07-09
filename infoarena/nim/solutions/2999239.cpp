#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

int main() {
    fin>>t;
    for (int i=0; i<t; i++) {
        fin>>n;
        int s=0, x;
        for (int j=1; j<=n; j++) {
            fin>>x;
            s=s ^ x;
        }
        if (s)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}