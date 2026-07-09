#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int fr[10000][5],pi1,pi2,n,v1[1030],v2[1030],nr[10030],k,lg,lgm,w[1030],m;
void inter();
void scan();
int main()
{
    scan();
    inter();
    for(int i=1;i<k;i++)
    {
        pi1=fr[i][1];
        pi2=fr[i][2];
        nr[lg=1]=v1[pi1];
        for(int j=i+1;j<=k;j++)
            if(fr[j][1]>=pi1&&fr[j][2]>=pi2)
                pi1=fr[j][1],nr[++lg]=v1[pi1],pi2=fr[j][2];
        if(lg>lgm)
        {
            lgm=lg;
            for(int i=1;i<=lg;i++)
                w[i]=nr[i];
        }
    }
    fout<<lgm<<'\n';
    for(int i=1;i<=lgm;i++)
        fout<<w[i]<<' ';
    fout<<'\n';
    return 0;
}
void inter()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(v1[i]==v2[j])
            {
                fr[++k][1]=i;
                fr[++k][2]=j;
                v2[j]=-1;
                break;
            }
    }
}
void scan()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
}
