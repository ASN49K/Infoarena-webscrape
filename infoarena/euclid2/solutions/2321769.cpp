#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,a,b,i,r;
int main()
{
    in>>n;
    for(i=1; i<=n; i++)
    {
        in>>a>>b;
        if(a < b)
    {

    a += b;
    b = a - b;
    a -= b;
    }
    r = a%b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    out<<b<<'\n';
    }
    return 0;
}
