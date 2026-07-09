#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int cmmdc(unsigned long long a,unsigned long long b)
{
    unsigned long long int t;
    while (b != 0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    unsigned long long n,i;
    ifstream f("euclid2.in");
    ofstream f2("euclid2.out");
    f>>n;
    for (i=1;i<=n;i++)
    {
        unsigned long long a,b;
        f>>a>>b;
        f2<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
