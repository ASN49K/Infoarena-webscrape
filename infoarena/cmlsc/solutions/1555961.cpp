#include <fstream>
using namespace std;
ofstream fout("cmlsc.out");
int a[1030],b[1030],DP[1030][1030];
void scriere(int i,int j)
{
    if(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            scriere(i-1,j-1);
            fout<<" "<<a[i];
        }
        else
        {
            if(DP[i-1][j]>DP[i][j-1])
                scriere(i-1,j);
            else
                scriere(i,j-1);
        }
    }
}
int main()
{
    ifstream fin("cmlsc.in");
    int n,m;
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
        fin.close();
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==0 || j==0)
                    DP[i][j]==0;
                else
                {
                    if(a[i]==b[j])DP[i][j]=DP[i-1][j-1]+1;
                    else
                    {
                        DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
                    }
                }
            }
        }
        fout<<DP[m][n]<<"\n";
        scriere(m,n);
}
