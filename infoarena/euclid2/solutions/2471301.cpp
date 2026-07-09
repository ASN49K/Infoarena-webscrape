#include <iostream>
#include <fstream>

using namespace std;

long long cmmdc(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b, a%b);
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
