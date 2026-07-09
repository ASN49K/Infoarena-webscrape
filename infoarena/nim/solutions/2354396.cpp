#include<bits/stdc++.h>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t;

int main()
{
    f>>t;
    while(t--)
    {
        int nr;
        f>>nr;
        int a=0;
        for(int i=1;i<=nr;++i)
        {
            int x;
            f>>x;
            a^=x;
        }
        if(a)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
}
