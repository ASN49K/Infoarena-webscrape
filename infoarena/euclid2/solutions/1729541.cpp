#include <iostream>
#include <fstream>
using namespace std;

int s(int a, int b)
{
    if(a==b)
        return a;
    else
        if(a>b)
            return s(a-b,b);
        else
            return s(a,b-a);
}

int i(int a, int b)
{
    if(b==0)
        return a;
    else
        return i(b,a%b);
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
        g<<i(a,b)<<endl;
    }
}
