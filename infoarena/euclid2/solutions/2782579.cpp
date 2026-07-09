#include <bits/stdc++.h>

using namespace std;

fstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    int t;
    int a, b;
    f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>a>>b;
        cout<<cmmdc(a, b)<<endl;
    }

    return 0;
}
