#include <iostream>
//#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b,cmmdc=1,mic;
        f>>a>>b;
        mic=min(a,b);
        for(int j=2;j<=mic;j++)
        {
            while(a%j==0 and b%j==0)
            {
                a/=j;
                b/=j;
                cmmdc*=j;
            }
            mic=min(a,b);
        }
        g<<cmmdc<<"\n";
    }
    return 0;
}
