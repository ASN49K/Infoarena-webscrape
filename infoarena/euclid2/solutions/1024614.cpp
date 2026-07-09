#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in", ios::in);
ofstream g("euclid2.out", ios::out);
long cmmdc( long a, long b)
{
    if(a==b)
    return a;
    else
    if(a>b)
    return cmmdc(a-b,b);
    else
    return cmmdc(a,b-a);}
int main()
{
    long t,i,a,b;
    f>>t;
    for(i=1;i<=t;i++)
    {
                     f>>a;
                     f>>b;
                     g<<cmmdc(a,b);}
    return 0;}
