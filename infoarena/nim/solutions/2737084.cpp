#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t,i,sumx,x;
int main()
{
    f>>t;
    for (;t--;)
    {
        f>>n;
        sumx=0;
        for (i=1;i<=n;i++)
        {
            f>>x;
            sumx=sumx^x;
        }
        if (sumx==0)
        {
            g<<"NU"<<'\n';
        }
        else
        {
            g<<"DA"<<'\n';
        }
    }
    return 0;
}
