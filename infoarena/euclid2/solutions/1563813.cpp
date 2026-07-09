#include <fstream>
using namespace std;

ifstream fin("algEuclid.in");
ofstream fout("algEuclid.out");

int algoritmEuclid(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int a, x, y;
    fin>>a;
    for(int i=0; i<a; i++)
    {
        fin>>x>>y;
        fout<<algoritmEuclid(x, y)<<'\n';
    }
    return 0;
}
