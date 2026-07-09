#include <fstream>

using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");

int n,m,s1[1030],s2[1030],sol[2030],ma[1030][1030],k,maxi;

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


    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(s1[i]==s2[j])
            {
                ma[i][j]=ma[i-1][j-1]+1;
            }

            else
            {
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            }
        }
    }

    fout<<ma[n][m]<<'\n';

    int i=n;
    int j=m;

    while(s1[i]||s2[j])
    {
        if(s1[i]==s2[j])
        {
            sol[++k]=s1[i];
            i--;
            j--;
        }

        else if(ma[i-1][j]<ma[i][j-1]){
            j--;
        }

        else{
            i--;
        }
    }

    for(int i=k;i>=1;i--)
    {
        fout<<sol[i]<<' ';
    }

    return 0;
}
