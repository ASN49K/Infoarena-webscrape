#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n,x,y;
    f>>n;
    for (; n;n-- )
        {f>>x>>y;
            g<<gcd(x,y);
            g<<endl;}

    return 0;
}
