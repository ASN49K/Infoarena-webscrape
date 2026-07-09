#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    int t, a, b, i, r;
    in>>t;
    for(i=1; i<=t; i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
