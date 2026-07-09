#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int main()
{
    int t, a,b, i,r;
    in>>t;
    for (i=0; i<t; i++)
    {
        in>>a>>b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<"\n";
    }
    return 0;
}
