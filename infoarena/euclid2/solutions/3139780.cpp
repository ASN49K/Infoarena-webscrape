#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b;
int main()
{
    fin >> T;
    while(T--){
        fin >> a >> b;
        while(b){
            int r = a%b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
}
