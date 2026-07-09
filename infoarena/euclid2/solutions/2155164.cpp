#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int cmmdc(int x,int y)
{
    while(y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
