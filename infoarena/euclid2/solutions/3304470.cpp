#include <fstream>
using namespace std;
ifstream  fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b;

int euclid(int x, int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    fin>>T;

    for(int i=1; i<=T; i++)
    {
        fin>>a>>b;
        fout<< euclid(a,b) << "\n";
    }

    return 0;
}
