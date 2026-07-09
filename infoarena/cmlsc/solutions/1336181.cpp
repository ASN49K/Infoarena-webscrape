#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,t,y[1025],v[1025],w[1025],i,z;

int cmlsc(int n, int m, int y[1025], int &t)
{
    if(m==0 || n==0)
        return 0;
    else
    {
        if(v[n]==w[m])
        {
            y[t]=v[n];
            t++;
            return 1+cmlsc(n-1,m-1,y,t);
        }
        else
            return max(cmlsc(n,m-1,y,t), cmlsc(n-1,m,y,t));

    }
}

int main()
{
    fin>>n>>m;

    for(i=1;i<=n;++i)
        fin>>v[i];

    for(i=1;i<=m;++i)
        fin>>w[i];

    z=cmlsc(n,m,y,t);

    fout<<z<<'\n';

    for(i=z-1;i>=0;--i)
        fout<<y[i]<<" ";

    return 0;
}
