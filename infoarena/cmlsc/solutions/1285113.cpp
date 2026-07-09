#include <cstdio>
#define maxim 1030
using namespace std;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int n,m,v[maxim][maxim],k[maxim][maxim],a[maxim],b[maxim],mama;
int ma=0,l,c,sol[maxim];

int main()
{int i,j;
fscanf(f,"%d %d",&n,&m);
for (i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
for (j=1;j<=m;j++) fscanf(f,"%d",&b[j]);

for (i=1;i<=n;i++) for (j=1;j<=m;j++)
        {if (a[i]==b[j])
                   {v[i][j]=v[i-1][j-1]+1;
                    k[i][j]=-1;
                    }
              else {if (v[i-1][j]>v[i][j-1])
                            {v[i][j]=v[i-1][j];
                             k[i][j]=1;
                             }
                       else {v[i][j]=v[i][j-1];
                             k[i][j]=2;
                             }
                    }
         }
for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (v[i][j]>ma)
        {ma=v[i][j];
         l=i;c=j;
         }
fprintf(g,"%d\n",ma);mama=ma;
while (ma!=0)
        {
         if (k[l][c]==-1) {sol[ma]=a[l];
                           ma--;
                           l--;c--;}else
         if (k[l][c]==2) {c--;}else
         if (k[l][c]==1) {l--;};

         }
for (i=1;i<=mama;i++) fprintf(g,"%d ",sol[i]);
return 0;
}
