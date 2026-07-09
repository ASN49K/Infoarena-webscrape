#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1025],y[1025],c[1025][1025],n,m;
void solve ()
{int i,j;
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
   if(x[i]==y[j])c[i][j]=c[i-1][j-1]+1;
   else c[i][j]=max(c[i-1][j],c[i][j-1]);

}

void afis ()
{ int i,j;
    g<<c[n][m]<<'\n';
    g<<x[n]<<" ";
    c[n][m]--;
    for(i=1;i<=n;i++)
        for(j=1;j<=m&&c[n][m];j++)
    {if(c[i][j]==c[n][m]){g<<x[i]<<" ";c[n][m]--;}

    }

}
int main()
{f>>n>>m;
 for(int i=1;i<=n;i++)f>>x[i];
 for(int i=1;i<=m;i++)f>>y[i];
 solve();
 afis();

    return 0;
}
