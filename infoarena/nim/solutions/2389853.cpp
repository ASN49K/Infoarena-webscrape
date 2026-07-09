#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");
int t,n,rez,a;

int main()
{
    f>>t;
    for(int i=0;i<t;i++)
    {
        rez=0;
        f>>n;
        for(int i=0;i<n;i++)
        {
            f>>a;
            rez^=a;
        }
        if(rez)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
