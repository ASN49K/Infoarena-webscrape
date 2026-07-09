#include <iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
    if(b>a)
        swap(a,b);
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
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
long long i,a,b,t;
f>>t;
for(i=1;i<=t;i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<endl;
}

    return 0;
}
