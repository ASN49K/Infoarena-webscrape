#include <bits/stdc++.h>
using namespace std;
int cmmdc(int a, int b){
    int r = 1;
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n, a, b;
    fin >> n;
    for(int i = 1; i <= n; ++i){
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
    return 0;
}
