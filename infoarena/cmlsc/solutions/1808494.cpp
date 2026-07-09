#include <fstream>

using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");

int n,m,s1[1030],s2[1030],sol[1030],ma[1030][1030],aux,k,maxi;

int main()
{
    fin>>n>>m;

    for(int i=1;i<=n;++i)
    {
        fin>>s1[i];
    }

    for(int i=1;i<=m;++i)
    {
        fin>>s2[i];
    }

    aux=1;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(s1[i]==s2[j])
            {
                ma[i][j]=ma[i-1][j-1]+1;

                if(ma[i][j]==aux)
                {
                    sol[++k]=s1[i];
                    aux++;
                }
            }

            else
            {
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            }
        }
    }

    fout<<ma[n][m]<<'\n';

    for(int i=1;i<=k;++i)
    {
        fout<<sol[i]<<' ';
    }

    return 0;
}
