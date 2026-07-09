#include <stdio.h>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, a, b;
    fin>>T;

    for (int i = 0; i < T; i++) {
        fin>>a>>b;
        fout<<gcd(a, b)<<'\n';
    }
    return 0;
}