
#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n;
    f>>n;
    for(int i=1;i<=n;i++)
    {
    long long a,b;
    f>>a>>b;
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
        g<<a<<'\n';
    }
    return 0;
}
