#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,r,n;
int gcd(int a, int b) {
    if(!b) return a;
    return gcd (b, a%b);
}
int main()
{
    fin>>n;
    while (n--)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
    }
    return 0;
}
