#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
#define N 1001000
#define DIM 10000
char buff[DIM];
int poz;
ifstream f("cmlsc.in");
inline void R(int &x)
{
    x=0;
    while(buff[poz]<'0'||buff[poz]>'9')
        if(++poz==DIM)
    {
        poz=0;
        f.read(buff,DIM);
    }
    while(buff[poz]>='0' && buff[poz]<='9')
    {
        x=x*10+buff[poz]-48;
        if(++poz==DIM)
        {
            poz=0;
            f.read(buff,DIM);
        }
    }
}
vector<int> a[N];
int d[N],v[N],w[N],i,j,n,k,m,it;
int Mx(int ls,int ld)
{
    if(ld-ls<2)
        return max(d[ls],d[ld]);
    int m=(ls+ld)/2;
        return max( Mx(ls,m),Mx(m+1,ld) );
}
int main()
{
    R(n);R(k);
    for(i=1;i<=n;++i)
        R(v[i]);
    for(i=1;i<=k;++i)
    {
        d[i]=0;
        R(w[i]);
        a[ w[i] ].push_back(i);
    }
    bool ok;
    for(i=1;i<=n;++i)
    {
        m=v[i];ok=0;
        for(j=0;j<a[m].size() && !ok;++j)
        {
            it=a[m][j];
            if(it>=i)
            {
                ok=1;
                d[it]=max( Mx(1,it-1)+1 ,d[it]);
            }
        }
    }
    ofstream g("cmlsc.out");
    g<<Mx(1,n);
    return 0;
}
