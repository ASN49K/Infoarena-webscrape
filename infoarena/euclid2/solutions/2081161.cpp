#include <fstream>
#include <algorithm>
#define ff first
#define s second

using namespace std;
ifstream fin ("struti.in");
ofstream fout("struti.out");

int main ()
{
    fin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            fin>>a;
            if(a==0)
            {
                v[i][j]=a;
                m1[i][j]=a;
                m2[i][j]=a;
            }
            else
            {
                v[i][j]=-1;
                m1[i][j]=-1;
                m2[i][j]=-1;
                if(ok==0)
                {
                    x=i;y=j;
                    ok=1;
                }
            }
        }
    p=1;u=1;
    c1[1].first=1;
    c1[1].second=1;
    v[1][1]=1;
    while(p<=u)
    {
        for(d=0;d<=8;d++)
        {
            iv=c1[p].first+di[d];
            jv=c1[p].second+dj[d];
            if(iv>=1&&iv<=x&&jv>=1&&jv<=y&&v[iv][jv]==0)
            {
                u++;
                c1[u].first=iv;
                c1[u].second=jv;
                v[iv][jv]=v[c1[p].first][c1[p].second]+1;
            }
        }
        p++;
    }
    u=0;p=1;
    for(i=1;i<x;i++)
    {
        c2[++u].first=i;
        c2[u].second=y;
        m1[i][y]=v[i][y];
    }
    while(p<=u)
    {
        for(d=0;d<=8;d++)
        {
            iv=c2[p].first+di[d];
            jv=c2[p].second+dj[d];
            if(iv>=1&&iv<=n&&jv>=y&&jv<=n&&m1[iv][jv]==0)
            {
                if(iv==n&&jv==n)
                {
                    p=u+1;
                    fout<<m1[c2[p].first][c2[p].second]+1;
                    break;
                }
                u++;
                c2[u].first=iv;
                c2[u].second=jv;
                m1[iv][jv]=m1[c2[p].first][c2[p].second]+1;
            }
        }
        p++;
    }
    u=0;p=1;
    for(j=1;j<y;j++)
    {
        c3[++u].first=x;
        c3[u].second=i;
        m2[x][i]=v[x][i];
    }
    while(p<=u)
    {
        for(d=0;d<=8;d++)
        {
            iv=c2[p].first+di[d];
            jv=c2[p].second+dj[d];
            if(iv>=1&&iv<=n&&jv>=y&&jv<=n&&m1[iv][jv]==0)
            {
                if(iv==n&&jv==n)
                {
                    p=u+1;
                    fout<<m1[c2[p].first][c2[p].second]+1;
                    break;
                }
                u++;
                c2[u].first=iv;
                c2[u].second=jv;
                m1[iv][jv]=m1[c2[p].first][c2[p].second]+1;
            }
        }
        p++;
    }
    return 0;
}
