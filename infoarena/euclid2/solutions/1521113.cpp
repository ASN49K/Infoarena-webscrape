#include <stdio.h>
#include <fstream>

using namespace std;

int T, A, B;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    fin>>T;
    for (; T; --T)
    {
        fin>>A>>B;
        fout<<gcd(A,B)<<endl;
    }
}
