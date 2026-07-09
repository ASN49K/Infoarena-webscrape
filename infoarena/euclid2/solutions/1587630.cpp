#include <fstream>

using namespace std;

int T, A, B;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

int main()
{


    fin>>T;
    for(int i=1;i<=T;++i)
    {
        fin>>A>>B;
        fout<<gcd(A, B);
    }

    return 0;
}
