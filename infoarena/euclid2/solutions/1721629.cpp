#include <iostream>
#include <fstream>
using namespace std;
ifstream si("euclid2.in");
ofstream so("euclid2.out");
int main()
{
    int q;
    si>>q;
    int a,b,r;
    while(q--)
    {
        si>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        so<<b<<'\n';
    }
    return 0;
}
