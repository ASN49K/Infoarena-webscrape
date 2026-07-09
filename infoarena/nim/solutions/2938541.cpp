#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n;
int main()
{
    f>>t;
    for(; t; t--)
    {
        f>>n;
        int ans=0;
        for(;n;n--)
        {
            int x;
            f>>x;
            ans^=x;
        }
        if(ans)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
