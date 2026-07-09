#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream gout("euclid2.out");

int A,B,T;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>A>>B;
        gout<<gcd(A,B)<<endl;
    }

    return 0;
}
