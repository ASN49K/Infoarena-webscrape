#include <iostream>
#include <fstream>
using namespace std;

int a,b,t;
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
    f>>t;
    for(int i=1; i<=t; i++)

    {

     f>>a>>b;
    g<<gcd(a,b)<<endl;
    }




    return 0;
}
