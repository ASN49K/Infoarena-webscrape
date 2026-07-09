#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int cmmdc(int a, int b)
{
    if (b==0) return a;
    return cmmdc(b, a%b);
}
int main()
{long T, a, b, i;
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<cmmdc(a, b)<<endl;
    }
    return 0;
}
