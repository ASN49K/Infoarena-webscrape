#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t;

int euclid(int a, int b) {
    if(b==0) return a;
    else return euclid(b, a%b);
}

int main()
{
    fin>>t;
    for(;t;t--) {
        fin>>a>>b;
        int max0 = max(a,b);
        int min0 = min(a,b);
        fout<<euclid(max0, min0)<<'\n';
    }
    return 0;
}
