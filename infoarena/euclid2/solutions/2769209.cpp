#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int x,int y)
{
    int r;
    r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
    int T,a,b,i;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
