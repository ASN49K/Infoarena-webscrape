#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b;

int gcd(int a, int b)
{
    if(b==0)   return a;
    return gcd(b,a%b);
}

int main()
{
    fin>>n;
    while(n--)
    {
        fin>>a>>b;
        fout<<gcd(a, b)<<'\n';
    }
    return 0;
}
