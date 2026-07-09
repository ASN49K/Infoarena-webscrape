#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,a,b;
    /// citire date
    f>>n;
    for (int i=1;i<=n;i++)
    {
        f>>a>>b;
        while (a!=b)
        {
            if (a>b)
            {
                a=a-b;
            }
            else
            {
                b=b-a;
            }
        }
        g<<a<<endl;
    }
    return 0;
}
