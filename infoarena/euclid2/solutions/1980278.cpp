#include <stdint.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
int32_t t, a, b;
fstream f1("euclid2.in", ios::in);
fstream f2("euclid2.out", ios::out);
int32_t cmmdc(int32_t a, int32_t b)
{
    if(b==0) return a;
    else return cmmdc(b, a%b);
}
int main()
{
    int32_t i;
    f1>>t;
    for(i=1; i<=t; i++)
    {
        f1>>a>>b;
        f2<<cmmdc(a, b)<<"\n";
    }
}
