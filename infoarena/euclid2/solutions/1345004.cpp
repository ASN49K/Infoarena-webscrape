#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long a,b;
int t;

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    f>>t;
    while(t)
    {
        t--;
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
