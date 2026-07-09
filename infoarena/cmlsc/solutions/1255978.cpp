#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,a[1030],b[1030],i,j,v[1030][1030],u[1030],nr=0;

int main ()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for (i=1; i<=n; i++)
    scanf("%d",&a[i]);
for (i=1; i<=m; i++)
    scanf("%d",&b[i]);

memset(v,0,sizeof(v));
for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            if(a[i]==b[j])  v[i][j]=v[i-1][j-1]+1;
                    else v[i][j]=max(v[i-1][j],v[i][j-1]);
}
printf("%d\n",v[n][m]);
i=n; j=m;
while (i>0 && j>0){
        if (a[i]==b[j]) { u[++nr]=a[i]; i--; j--;}
            else {
                if (v[i-1][j]==v[i][j-1]) i--;
                    else j--;
            }
}
for (i=nr; i>=1; i--) {
    printf("%d ",u[i]);
}
printf("\n");
fclose(stdout);
return 0;
}
