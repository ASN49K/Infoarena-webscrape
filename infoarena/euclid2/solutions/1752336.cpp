#include <fstream>

using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int euclid(int a, int b)
{
    int r=a%b;

    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}
int main()
{
    int a, b, t;
    fin>>t;

    for(int i=1; i<=t; i++)
    {
        fin>>a>>b;
        fout<<euclid(a, b)<<'\n';
    }
}
