#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, r;
int gcd(int a, int b)
{
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
    int t;
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
        t--;
    }
    return 0;
}
