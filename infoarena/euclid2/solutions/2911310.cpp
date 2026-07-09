#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int divizor(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}

int main()
{
    int nr;
    int a,b;
    f>>nr;
    for(int i=0;i<nr;i++)
    {
        f>>a>>b;
        g<<divizor(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
