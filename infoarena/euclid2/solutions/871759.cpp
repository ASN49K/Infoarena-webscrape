#include<iostream>
#include<fstream>
using namespace std;
ifstream f;
ofstream g;
int rin(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int i,t,x,y;
    f.open("euclid2.in");
    g.open("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<rin(x,y)<<endl;
    }
    f.close();
    g.close();
}
