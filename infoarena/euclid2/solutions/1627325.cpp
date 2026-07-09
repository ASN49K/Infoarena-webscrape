#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    if(!a) return b;
    else if(!b) return a;
    int c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int t,a,b;
int main()
{
    ios::sync_with_stdio(false);
    f>>t;
    while(t--)
    {
       f>>a>>b;
       g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
