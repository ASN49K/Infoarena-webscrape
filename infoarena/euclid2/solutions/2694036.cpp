#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int m, int n)
{
    int r;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}

int main()
{
    long long n, i, x, y;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> x >> y;
        fout << Euclid(x,y) <<"\n";
    }

    return 0;
}
