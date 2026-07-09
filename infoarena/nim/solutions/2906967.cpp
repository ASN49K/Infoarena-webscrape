#include<bits/stdc++.h>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,l,n,i,ans,x;
    f>>t;
    for(l=1;l<=t;l++)
    {
        ans=0;
        f>>n;
        for(i=1;i<=n;i++)
        {
            f>>x;
            ans=ans ^ x;
        }
        if(ans==0)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
    return 0;
}
