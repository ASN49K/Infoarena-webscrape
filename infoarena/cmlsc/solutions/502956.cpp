#include<cstdio>
int main()
{int r,z[2000][2000]={0},i,j,n,m,x[2000],y[2000],k,v[2000],max,t=1,l[2000],p=0,g[2000];
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
for(i=1;i<=m;i++)
      scanf("%d",&y[i]);
for(r=1;r<=n;r++)
      {k=0;
      for(j=1;j<=m;j++)
      if(x[r]==y[j])
             {k++;
             z[r][k]=j;}
      g[r]=k;}
k=0;
for(i=1;i<=n;i++)
      {for(j=1;j<=g[i];j++)
      if(z[i][j]>p)
             {k++;
             v[k]=z[i][j];
             p=v[k];
             break;}}
l[k]=1;
for(i=k-1;i>=1;i--)
      {max=0;
      for(j=i+1;j<=k;j++)
      if(v[j]>=v[i]&&l[j]>max)
              max=l[j];
      l[i]=max+1;}
max=l[1];
for(i=2;i<=k;i++)
if(l[i]>max)
      {max=l[i];
      t=i;}
printf("%d\n",max);
printf("%d ",y[v[t]]);
for(i=t+1;i<=k;i++)
if(v[i]>v[t]&&l[i]==max-1)
      {printf("%d ",y[v[i]]);
      max--;}
printf("\n");
fclose(stdin);
fclose(stdout);
return 0;}
