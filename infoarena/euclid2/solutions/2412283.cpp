#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

unsigned long t;
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
    in>>t;
    for(unsigned long i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
