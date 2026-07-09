#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int cmmdc (int a, int b)
{
    while (b)
    {
        int rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}
int main ()
{

    int t;
    in>>t;
    while (t--)
    {
        int a,b;
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
