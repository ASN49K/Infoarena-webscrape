#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    if(a==b)
        return a;
    else
        if(a>b)
            return euclid(a-b,b);
        else
            return euclid(a,b-a);
}

int euclid2(int a, int b)
{
    if(b==0)
        return a;
    else
        return euclid2(b,a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long t,a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid2(a,b)<<endl;
    }
}
