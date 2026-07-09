#include <cstdio>
#include <iostream>
#define nmax 1030

using namespace std;
FILE *f1,*f2;
int n,m,x[nmax],y[nmax],a[nmax][nmax],max1,i,j;

void afis(int i,int j)
{while (x[i]!=y[j])
if (a[i-1][j]>a[i][j-1]) i--;
else j--;
if (a[i-1][j-1]>0) afis(i-1,j-1);
fprintf(f2,"%d ",x[i]);
}

int main()
{f1 = fopen("cmlsc.in","r");
f2 = fopen("cmlsc.out","w");
fscanf(f1,"%d %d",&n,&m);
for (i=1;i<=n;i++) fscanf(f1,"%d",&x[i]);
for (i=1;i<=m;i++) fscanf(f1,"%d",&y[i]);
for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
{if (x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
else
a[i][j]=max(a[i-1][j],a[i][j-1]);
}
fprintf(f2,"%d\n",a[n][m]);
afis(n,m);
fclose(f1);
fclose(f2);
    return 0;
}

//Challenges are what make life interesting and overcoming them is what makes life meaningful.
