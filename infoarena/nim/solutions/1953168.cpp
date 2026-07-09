#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int n,t,x,s;


int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>n;
        s=0;
        for(;n;n--)
            f>>x,s^=x;
        if(s==0)
            g<<"NU\n";
        else
            g<<"DA\n";

    }
    return 0;
}


