#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int main()
{
    f>>t;
    while(t!=0)
    {
        t--;
        f>>a>>b;
    while(a!=b)
        {if(a>b)
            a=a-b;
        else b=b-a;}
    g<<b<<"\n";
    }
    return 0;
}
