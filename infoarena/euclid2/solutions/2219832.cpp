#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{   int a,b,r,t,i;

    f>>t;
    for(i=0;i<t;i++)
    {
    f>>a>>b;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
