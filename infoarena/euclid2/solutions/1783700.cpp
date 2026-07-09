#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b,c;
    /// citire date
    f>>n;
    for (int i=1;i<=n;i++)
    {
        f>>a>>b;
        while (b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }

        g<<a<<endl;
    }
    return 0;
}
