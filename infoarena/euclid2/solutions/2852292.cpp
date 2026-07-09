#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,t,i;

int euclid(int x,int y)
{
    while(x!=y)
        if(x>y)
          x=x-y;
        else
          y=y-x;
    return x;
}

void read()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
}


int main()
{
    read();
    return 0;
}
