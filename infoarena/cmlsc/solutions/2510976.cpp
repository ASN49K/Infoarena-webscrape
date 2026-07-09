#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX=(1<<10);
int n,m,sir1[NMAX],sir2[NMAX],d[NMAX][NMAX],sir[NMAX],lenght,i,j;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>sir1[i];
    for(int j=1; j<=m; j++)
        cin>>sir2[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        if(sir1[i]==sir2[j])
            d[i][j]=1+d[i-1][j-1];
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    for(i=n,j=m; i;)
    {
        if(sir1[i]==sir2[j])
            sir[++lenght]=sir1[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    cout<<lenght<<endl;
    for(int i=lenght;i>=1;--i)
    cout<<sir[i]<<" ";
    return 0;
}
