#include <fstream>
using namespace std;
int x[1025],y[1025],L[1025][1025],v[1025];
ofstream g("cmlsc.out");
void afisare(int i,int j)
{
    int k=0;
    while(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            v[k]=x[i];
            k++;
            i--;
            j--;
        }
        else
            if(L[i][j]==L[i-1][j])
                i--;
            else
                j--;
    }
    for(k--;k>=0;k--)
        g<<v[k]<<" ";
}
int main()
{
    int i,j,n,m;
    ifstream f("cmlsc.in");
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i][j-1],L[i-1][j]);

        }
    }

    g<<L[n][m]<<endl;
    afisare(n,m);
    return 0;
}
