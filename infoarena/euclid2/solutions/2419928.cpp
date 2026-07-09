//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t;
int cmmdc(int a,int b)
{
    while(a%b)
    {
      int r=a%b;
        a=b;
        b=r;
    }
    return b;
}
int main()
{
    in>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y; in>>x>>y;
        out<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
