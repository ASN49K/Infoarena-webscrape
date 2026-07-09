#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b)
{
    int r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int n,a,b;
    fin >> n;
    for (int i=1;i<=n;i++)
    {
        fin >> a >> b;
        fout << gcd(max(a,b),min(a,b))<<"\n";
    }
}
