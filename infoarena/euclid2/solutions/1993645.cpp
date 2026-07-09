#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a,b;
int i,t;

int gcd (int a, int b)
{

    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<gcd(a,b)<<"\n";
    }
    return 0;
}
