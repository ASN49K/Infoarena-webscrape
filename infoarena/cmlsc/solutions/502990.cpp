#include<cstdio>
#define NR 32000
long q,c[NR],r,z[2000][2000]={0},i,j,n,m,x[NR],y[NR],k,max,t=1,p,g[NR],z1[2000][2000]={0};
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%ld %ld\n",&n,&m);
for(i=1;i<=n;i++)
      scanf("%ld",&x[i]);
for(i=1;i<=m;i++)
      scanf("%ld",&y[i]);
for(i=1;i<=n;i++)
      {k=0;
      for(j=1;j<=m;j++)
      if(x[i]==y[j])
             {k++;
             z[i][k]=j;}
      g[i]=k;}
for(q=1;q<=n;q++)
      {k=0;
      p=0;
      for(i=q;i<=n;i++)
             {for(j=1;j<=g[i];j++)
             if(z[i][j]>p)
                    {k++;
                    z1[q][k]=z[i][j];
                    p=z1[q][k];
                    break;}}
      c[q]=k;}
max=0;
for(i=1;i<=n;i++)
if(max<c[i])
      {max=c[i];
      j=i;}
printf("%ld\n",c[j]);      
for(k=1;k<=c[j];k++)
if(z1[j][k]>0)
      printf("%ld ",y[z1[j][k]]);
printf("\n");
fclose(stdin);
fclose(stdout);
return 0;}
