#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void citire(int &a, int &b)
{
    f>>a;
    f>>b;
}
int cmmdc(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return b;
}
int main()
{
    int t, a, b, perechi;
    f>>t; perechi=0;
    while(perechi!=t)
    {
        citire(a,b);
        g<<cmmdc(a,b)<<endl;
        perechi++;
    }
    return 0;
}
