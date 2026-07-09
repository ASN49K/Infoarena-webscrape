#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
    while(y)
    {
        int t=y;
        y=x%y;
        x=t;
    }
    return x;
}

int n,x,y;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
