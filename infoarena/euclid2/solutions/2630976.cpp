#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int cmmdc(unsigned int a, unsigned int b)
{
    if(!b)return a;
    else return cmmdc(b,a%b);
}
    unsigned int n;
    unsigned int a, b;
int main()
{

    f>>n;
    while(n)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
        n--;
    }
    return 0;
}
