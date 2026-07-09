#include <iostream>
#include <fstream>
using namespace std;

int a,b,n,r;
int gcd(int a, int b)
{
    if(!b) return a;
    if(a>b) return gcd(a-b,b);
    return gcd(a, b-a);
}

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f>>n;
    for(int i=1; i<=n; i++)

    {

     f>>a>>b;
    g<<gcd(a,b)<<endl;
    }




    return 0;
}
