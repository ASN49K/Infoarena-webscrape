#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b,a % b);
}

int main()
{
    int t;
    fin >> t;
    while(t--)
    {
        long long a,b;
        fin >> a >> b;
        fout << gcd(a,b) << endl;
    }
}
