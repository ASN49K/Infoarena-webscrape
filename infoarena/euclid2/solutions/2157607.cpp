#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned int a, b;
unsigned short int t;
int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
}
int main()
{
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
        t--;
    }
    return 0;
}
