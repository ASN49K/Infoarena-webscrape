#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long a,b;
int t;

int cmmdc(int a, int b)
{
    if(!b)
        return a;
    else
        return (b,a%b);
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
