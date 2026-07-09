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
    long a,b;
    while(!f.eof())
    {
                     f>>a;
                     f>>b;
                     g<<cmmdc(a,b);}
    f.close();
    return 0;}
