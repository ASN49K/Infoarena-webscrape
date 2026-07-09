#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long cmmdc(long a, long b)
{
    if(a*b==0) return a+b;
    else
    {
        while(a*b!=0)
        {
            if(a>b) a=a%b;
            else b=b%a;
        }
        return a+b;
    }


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
