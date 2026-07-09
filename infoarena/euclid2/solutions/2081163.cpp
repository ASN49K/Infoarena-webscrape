#include <bits/stdc++.h>

using namespace std;

int euclid(int a,int b)
{
    int c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int a,b,n,i;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> n;

    for(i=1;i<=n;i++)
    {
        f >> a >> b;
        g << euclid(a,b) << "\n";
    }

    return 0;
}
