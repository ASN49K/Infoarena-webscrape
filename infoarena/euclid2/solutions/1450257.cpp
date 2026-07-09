#include <fstream>
using namespace std;
int a, b, r;
int main()
{
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    f>>a>>b;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    if (a==1)   g<<0;
    else    g<<a;
    return 0;
}
