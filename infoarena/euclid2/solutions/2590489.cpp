#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
#define N 1000005
int n,x,y,T[N],k;
int euclid(int a, int b)
{  int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
void citire()
{
    in>>n;
    for(int i=1; i<=n; ++i)
    {
        in>>x>>y;
        T[++k]=euclid(x,y);
    }
}
void afisare()
{
    for(int i=1; i<=k; ++i)
        out<<T[i]<<"\n";
}

int main()
{
   citire();
   afisare();
    return 0;
}
