#include <iostream>
#include <fstream>

#define ll long long

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
ll a, b;

long long cmmdc(long long a, long long b)
{
    if(a == b)
        return a;
    else if(a < b)
    {
        ll aux = a;
        a = b;
        b = aux;
    }
    while(b)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> t;
    for(int i = 1; i <= t; ++i)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    return 0;
}
