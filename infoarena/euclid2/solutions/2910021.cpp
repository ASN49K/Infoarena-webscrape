#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,m;
    fin>>n>>m;
    while(m){
        int r=n%m;
        n=m;
        m=r;
    }
    fout<<n;
    return 0;
}
