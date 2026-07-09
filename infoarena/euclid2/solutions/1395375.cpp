#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned cmmdc(unsigned a, unsigned b)
{
    if(b == 0)
        return a;
    else return cmmdc(b, a % b);
}
int main()
{
    unsigned T,a,b;
    f>>T;
    for(unsigned i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b);
        g<<endl;
    }
    return 0;

}
