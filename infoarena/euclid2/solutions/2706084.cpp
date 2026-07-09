#include <bits/stdc++.h>

using namespace std;

ifstream in("ciur.in");
ofstream out("ciur.out");
const int N=1000010;
int n, nr;
bitset<N> p;
int main()
{
    in>>n;
    if(n>=2)
        nr++;
    int i;
    for(i=3; i*i<=n; i+=2)
        if(p[i]==0)
        {
            nr++;
            for(int j=i*i; j<=n; j+=2*i)
                p[j]=1;
        }
    for( ; i<=n; i+=2)
        if(p[i]==0)
           nr++;
    out<<nr;
    return 0;
}