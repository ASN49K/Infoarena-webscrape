#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int n,int m)
{
    int r;
    while(m)
    {
        r=n%m;
        n=m;
        m=r;
    } return n;
}

int main()
{
    int n,m,p,i;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>m>>p;
        fout<<cmmdc(m,p)<<endl;
    }
    return 0;
}
