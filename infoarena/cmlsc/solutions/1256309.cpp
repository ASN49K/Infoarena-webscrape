#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[1025],b[1025],i,j,v[1025][1025],u[1025],nr=0;
int main ()
{ofstream g("cmlsc.out");
    freopen("cmlsc.in","r",stdin);
scanf("%d%d",&n,&m);
for (i=1; i<=n; i++)
    scanf("%d",&a[i]);
for (i=1; i<=m; i++)
    scanf("%d",&b[i]);


for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            if(a[i]==b[j])  v[i][j]=v[i-1][j-1]+1;
                    else v[i][j]=max(v[i-1][j],v[i][j-1]);
}
g<<v[n][m]<<'\n';
i=n; j=m;
while (i>0 && j>0){
        if (a[i]==b[j]) { u[++nr]=a[i]; i--; j--;}
            else {
                if (v[i-1][j]==v[i][j-1]) i--;
                    else j--;
            }
}
for (i=nr; i>=1; i--) {
   g<<v[i]<<" ";
}
return 0;
}
