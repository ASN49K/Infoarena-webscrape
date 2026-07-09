#include <iostream>
//#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
int euclid(int a, int b)
{
    if(a*b==0)
        return max(a,b);
    else return euclid(min(a,b),max(a,b)%min(a,b));
}
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
