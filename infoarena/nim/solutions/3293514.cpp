#include <iostream>
#include <bits/stdc++.h>
#define VMAX 1000005
#define INF 1000000000000000000
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");

int numere[VMAX];

signed main()
{
    long long int n,m,i,j,k,t,q,nr;
    fin>>t;
    while(t--)
    {
        fin>>n;
        nr=0;
        for(i=1;i<=n;i++)
        {
            fin>>j;
            nr=nr^j;
        }
        if(nr!=0)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }


    return 0;
}
