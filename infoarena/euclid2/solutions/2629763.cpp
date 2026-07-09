#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a, long long b)
{
    if(a == 0)
        return b;
    return gcd(b % a,a);
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
