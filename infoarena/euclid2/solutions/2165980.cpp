#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,k,a,b,r;
int main()
{
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>a>>b;
            while(b>0)
            {r=a%b;a=b;b=r;}
        g<<a<<endl;
    }
    return 0;
}
