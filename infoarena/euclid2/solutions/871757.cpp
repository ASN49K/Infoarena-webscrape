#include<iostream>
#include<fstream>
using namespace std;
ifstream f;
ofstream g;
int rin(int a,int b)
{
    int r;
    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
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
        cout<<rin(x,y);
    }
    f.close();
    g.close();
}
