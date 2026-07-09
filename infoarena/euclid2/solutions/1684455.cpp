#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    int n,i,a,b,r;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a>>b;
        while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<"/n";
    }
    return 0;
}
