#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long n;
unsigned long long a,b;

unsigned long long cmmdc(unsigned long long a, unsigned long long b)
{
    if(b>a)
        swap(a,b);
    unsigned long long c=a%b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    f>>n;
    for(unsigned long i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
