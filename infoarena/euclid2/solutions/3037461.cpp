#include <bits/stdc++.h>
using namespace std;
int T,a,b;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    fin >> T;
    while(T--){
        fin >> a >> b;
        int r;
        while(b){
            r = a%b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    return 0;
}
