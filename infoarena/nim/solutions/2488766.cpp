#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t,a[10001];

int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>n;
        for(int j=1;j<=n;j++)
        {
            f>>a[i];
        }
        if(n%2==1)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
