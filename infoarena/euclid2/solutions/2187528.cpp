#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long cmmdc(long a, long b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;


}

int main()
{
    int T,x,y;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }


    return 0;
}
