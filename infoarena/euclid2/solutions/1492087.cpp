#include <fstream>
using namespace std;
int a,b,x,r;
int main()
{
    ifstream intrare ("euclid2.in");
    ofstream iesire ("euclid2.out");
    intrare>>x;
    for (int i=0;i<x;i++)
    {
        intrare>>a>>b;
        r=a%b;
        while (r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        iesire<<b<<'\n';
    }
    return 0;
}
