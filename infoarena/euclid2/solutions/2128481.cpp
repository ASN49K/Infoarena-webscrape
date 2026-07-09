#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
    {
        return (b) ? cmmdc(b,a%b):a;
    }


int main()
{
    int t,i,a,b;
    f>>t;
    for(i=1;i<=t;i++)
    {f>>a>>b;
       g<<cmmdc(a,b)<<'\n';
    }


    return 0;
}
