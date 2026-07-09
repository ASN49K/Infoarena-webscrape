#include<cstdio>
#define NR 32000
long q,c[NR],v[NR],d,r,s[2000][2000]={0},i,j,n,m,x[NR],y[NR],k,max,t=1,p=0,g[NR],z[2000][2000]={0};
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%ld %ld\n",&n,&m);
for(i=1;i<=n;i++)
      scanf("%ld",&x[i]);
for(i=1;i<=m;i++)
      scanf("%ld",&y[i]);
for(i=1;i<=n;i++)
      {for(j=1;j<=m;j++)
             {if(x[i]==y[j])
                      {s[i][j]=s[i-1][j-1]+1;
                      z[i][j]=1;}
             else
                      s[i][j]=s[i-1][j-1];
             if(s[i][j]<s[i-1][j])
                      s[i][j]=s[i-1][j];
             if(s[i][j]<s[i][j-1])
                      s[i][j]=s[i][j-1];}}
printf("%ld\n",s[n][m]);
k=s[n][m];
for(i=n;i>=1;i--)
       {for(j=m;j>=1;j--)
       if(s[i][j]==k)
              {v[k]=y[j];
              d=j;}}
for(i=k-1;i>=1;i--)
       {for(j=1;j<=n;j++)
       if(i==s[j][d-1])
              {v[i]=y[d-1];
              d--;
              break;}}
for(i=1;i<=k;i++)
       printf("%ld ",v[i]);              
printf("\n");
fclose(stdin);
fclose(stdout);
return 0;}
