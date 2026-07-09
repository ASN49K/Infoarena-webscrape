#include <bits/stdc++.h>
using namespace std;
ifstream fein("nim.in");
ofstream g("nim.out");
#define pii pair<int,int>

int n, t, x;

int main()
{
    fein>>t;
    for(int m=1;m<=t;m++)
    {
        fein>>n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            fein>>x;
            s ^= x;
        }
        if(s==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<"\n";
    }

    return 0;
}
