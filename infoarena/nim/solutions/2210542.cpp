#include<bits/stdc++.h>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,Xor;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        Xor=0;
        for(;n;--n)
        {
            int nr;
            f>>nr;
            Xor^=nr;
        }
        if(Xor)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
