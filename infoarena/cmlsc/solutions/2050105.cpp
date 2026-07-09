#include <cstdio>
#include <algorithm>
#define N 1030
using namespace std;

FILE *in= fopen("cmlsc.in","r");
FILE *out= fopen("cmlsc.out","w");

int n,m;
int v[N],w[N],a[N][N];
vector <int> sol;

int main()
{
    fscanf(in,"%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        fscanf(in,"%d",&v[i]);

    for(int i=1;i<=m;i++)
        fscanf(in,"%d",&w[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(v[i]==w[j])
            a[i][j]= a[i-1][j-1] +1;

            else a[i][j]=max(a[i-1][j],a[i][j-1]);

    int i=n,j=m;
    while(i && j)
    {
        if(v[i]==w[j])
        {
            sol.push_back(v[i]);
            i--;
            j--;
        }
        else if(a[i][j-1]>a[i-1][j])
            j--;
        else i--;
    }
    fprintf(out,"%d\n",sol.size());
    for(i=sol.size()-1;i>=0;i--)
        fprintf(out,"%d ",sol[i]);
    return 0;
}
