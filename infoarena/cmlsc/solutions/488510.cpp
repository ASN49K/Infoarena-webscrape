#include<stdio.h>
#define max(a,b) (a>b?a:b)
int n,m,i,j,v[1100],v2[1100],a[1100][1100];
FILE *f,*g;
void recon(int i, int j )
{

if (i>0 & j>0) {
    if (v[i]==v2[j]) {
                        recon(i-1,j-1);
                        fprintf(g,"%d ",v[i]);
                        }
                else
                            if (a[i][j-1]>a[i-1][j]) recon(i,j-1);
                                                else recon(i-1,j);
           }
}
int main() {
f=fopen("cmlsc.in","r");
g=fopen("cmlsc.out","w");
fscanf(f,"%d%d",&n,&m);

for (i=1;i<=n;i++) fscanf(f,"%d",&v[i]);
for (j=1;j<=m;j++) fscanf(f,"%d",&v2[j]);

for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v[i]==v2[j]) a[i][j]=a[i-1][j-1]+1;
                    else a[i][j]=max(a[i-1][j],a[i][j-1]);

fprintf(g,"%d\n",a[n][m]);
recon(n,m);
fclose(g);
return 0;
}
