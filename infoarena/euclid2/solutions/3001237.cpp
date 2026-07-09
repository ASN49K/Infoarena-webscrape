#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n,a,b;
    fin>>n;
    for(int i = 1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<Euclid(a,b)<<'\n';
    }
    return 0;
}
