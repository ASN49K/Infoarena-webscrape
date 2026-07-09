#include <bits/stdc++.h>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int v[10005];
int main()
{
    int t,n;
    in>>t;
    while(t--)
    {
        in>>n;
        int sol=0;
        for(int i=1;i<=n;i++)
        {
            in>>v[i];
            sol^=v[i];
        }
        if(sol)
            out<<"DA\n";
        else
            out<<"NU\n";
    }
}
