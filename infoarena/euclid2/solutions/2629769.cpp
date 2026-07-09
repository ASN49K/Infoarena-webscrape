#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a, long long b)
{
    long long c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int t;
    fin >> t;
    while(t--)
    {
        long long a,b;
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
}
