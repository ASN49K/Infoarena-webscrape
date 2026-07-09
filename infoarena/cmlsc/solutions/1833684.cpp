#include <stdio.h>
using namespace std;
short int v3[1025][1027];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    short int maxx=0,j,n,m,i,v[1025],v2[1025],v4[257];
    scanf("%hu%hu",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%hu",&v[i]);
    for(i=1; i<=m; i++)
        scanf("%hu",&v2[i]);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(v[i] == v2[j])
                v3[i][j] = v3[i-1][j-1]+1;
            else v3[i][j] = ((v3[i-1][j]>v3[i][j-1]) ? v3[i-1][j] : v3[i][j-1]);
        }
    }
    i=n, j=m;
    while(i){
        if(v[i] == v2[j])
            v4[++maxx] = v[i],i--,j--;
        else if(v3[i-1][j] < v3[i][j-1])
        j--;
        else i--;
    }
    printf("%hu\n",maxx);
    for(i=maxx; i>=1; i--)
            printf("%hu ",v4[i]);
    return 0;
}
