#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int m, int n)
{
    while(m!=n)
        if(n<m)
          m=m-n;
        else
           n=n-m;
    return n;
}

int main()
{
    int n, i, x, y;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> x >> y;
        fout << Euclid(x,y) <<"\n";
    }

    return 0;
}
