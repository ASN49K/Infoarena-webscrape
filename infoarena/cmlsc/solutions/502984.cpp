#include<cstdio>
int q,c[2000],r,z[2000][2000]={0},i,j,n,m,x[2000],y[2000],k,v[2000],max,t=1,l[2000],p,g[2000],z1[2000][2000];
int main()
{freopen("cmlsc.in","rt",stdin);
freopen("cmlsc.out","wt",stdout);
scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
for(i=1;i<=m;i++)
      scanf("%d",&y[i]);
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
printf("%d\n",c[j]);
for(i=1;i<=c[j];i++)
      printf("%d ",y[z1[j][i]]);
printf("\n");
/*k=c[j];
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
printf("\n");*/
fclose(stdin);
fclose(stdout);
return 0;}
