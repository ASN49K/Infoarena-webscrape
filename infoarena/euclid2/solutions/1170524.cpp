#include <fstream>
using namespace std;
ifstream is ("euclid2.in");
ofstream os ("euclid2.out");

int t, a, b;
int Cmmdc(int a, int b);
int main()
{
    is >> t;
    while(t)
    {
        is >> a >> b;
        os << Cmmdc(a, b) << '\n';
        --t;
    }
    return 0;
}
int Cmmdc(int a, int b)
{
    int r;
    if(b == 0)
        return a;
    do
    {
        r = a % b;
        a = b;
        b = r;
    }while(r);
    return a;
}
