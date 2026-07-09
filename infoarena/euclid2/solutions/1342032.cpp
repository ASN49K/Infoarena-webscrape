#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,x,y;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    fin>>t;
    while(t)
    {
        fin>>x>>y;
        fout<<gcd(x,y)<<"\n";
        t--;
    }
    return 0;
}

