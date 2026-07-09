#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,r=1,a,b;
    f>>n;
    for(i=1;i<=n;i++)
    { f>>a>>b;
        r=1;
    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
    }
    return 0;
}
