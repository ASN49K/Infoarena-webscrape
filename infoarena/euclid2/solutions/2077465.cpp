#include <iostream>
#include <fstream>

using namespace std;

int euclid(long long a, long long b)
{
    long long m;
    while(b)
    {
        m = a % b;
        a = b;
        b = m;
    }
    return a;
}
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{

    long long a,b,n;
    fin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        fin >> a >> b;
        fout << euclid(a,b) << "\n";
    }
    return 0;
}
