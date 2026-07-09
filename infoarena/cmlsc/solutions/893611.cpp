#include <stdio.h>
#include <iostream>


using namespace std;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");

int n,m,i,v[1025],s[1025][1025],a[1025],c[1025],j,nr;
int main()
{
 fscanf(f,"%d%d",&n,&m);
 for(i=1;i<=n;i++)
  fscanf(f,"%d",&v[i]);
 for(i=1;i<=m;i++)
  fscanf(f,"%d",&a[i]);
 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 if (v[i]==a[j])s[i][j]=1+s[i-1][j-1];
 else s[i][j]=max(s[i-1][j],s[i][j-1]);


 fprintf(g,"%d\n",s[n][m]);

 nr=s[n][m];
for(i=n;i>=1;i--)
for(j=m;j>=1;j--)
 if( nr!=0 && s[i][j]==nr && v[i]==a[j])
    {
        nr--;
        c[++c[0]]=a[j];
    }
for(i=c[0];i>=1;i--)
  fprintf(g,"%d ",c[i]);


fclose(g);
return 0;
}
