#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short a[1025],b[1025],l[1026][1026],n,m,i,j;
int main()
{
    f>>n>>m;for(i=1;i<=n;i++)f>>a[i];for(i=1;i<=m;i++)f>>b[i];

    if(a[n]==b[m])l[n][m]=1;else l[n][m]=0;
    for(j=m-1;j>=1;j--)if(a[n]==b[j])l[n][j]=1;else l[n][j]=l[n][j+1];
    for(i=n-1;i>=1;i--)if(b[m]==a[i])l[m][i]=1;else l[m][i]=l[m][i+1];

    for(i=0;i<=n+1;i++)l[i][m+1]=-1;
    for(i=0;i<=m+1;i++)l[n+1][i]=-1;

    for(i=n-1;i>=1;i--)
        for(j=m-1;j>=1;j--)
            if(a[i]==b[j])l[i][j]=l[i+1][j+1]+1;
                else if(l[i+1][j]>l[i][j+1])l[i][j]=l[i+1][j];else l[i][j]=l[i][j+1];

    g<<l[1][1]<<endl;

    i=j=1;
    int s=l[1][1];
    while(s>0)
    {
        if(a[i]==b[j]){g<<a[i]<<" ";i=i+1;j=j+1;s--;}
            else if(l[i][j+1]>l[i+1][j])j=j+1;else i=i+1;
    }
    return 0;
}
