#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

#define MAXMN 1024

int a[MAXMN+1];
int b[MAXMN+1];
int sol[MAXMN+1];
int d[MAXMN+1][MAXMN+1];

int main()
{
    int m, n;
    cin>>m>>n;
    int i;
    for(i=1; i<=m; i++)
        cin>>a[i];
    for(i=1; i<=n; i++)
        cin>>b[i];
    int j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]!=b[j])
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            else
                d[i][j]=d[i-1][j-1]+1;
    int maxl;
    maxl=0;
    i=m;
    j=n;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol[maxl++]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    cout<<maxl<<'\n';
    for(i=maxl-1; i>=0; i--)
        cout<<sol[i]<<" ";
    return 0;
}
