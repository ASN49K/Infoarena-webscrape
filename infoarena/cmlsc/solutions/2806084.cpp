#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int x[1030],y[1030],n,m,t[1030][1030],sol[1030],k;

int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)f>>x[i];
    for(int i=1; i<=n; i++)f>>y[i];

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(x[i]==y[j])t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    g<<t[m][n]<<'\n';
    int i=m;
    int j=n;
    while(i)
    {
        if(x[i]==y[j])sol[++k]=x[i],i--,j--;
        else if(t[i][j-1]>t[i-1][j])j--;
        else
            i--;
    }
    for(i=k; i>=1; i--)g<<sol[i]<<" ";
    return 0;

}
