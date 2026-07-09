#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b;
    fin >> t;
    for(int p=0; p<t; p++) {
        fin >> a >> b;
        int r=a%b;
        while(r!=0) {
            a=b;
            b=r;
            r=a%b;
        }
        fout << b << "\n";
    }
    return 0;
}
