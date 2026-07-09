#include <iostream>
#include <fstream>

using namespace std;

int r,i,n,t,x,y;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
