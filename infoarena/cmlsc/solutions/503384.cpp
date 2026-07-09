#include<cstdio>
int v[1025],d,s[1025][1025],i,j,n,m,x[1025],y[1025],k,e;
int main()
{freopen("cmlsc.in","rt",stdin);
freopen("cmlsc.out","wt",stdout);
scanf("%d %d\n",&n,&m);
for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
for(i=1;i<=m;i++)
      scanf("%d",&y[i]);
for(i=0;i<=n;i++)
      s[i][0]=0;
for(j=0;j<=m;j++)
      s[0][j]=0;
for(i=1;i<=n;i++)
      {for(j=1;j<=m;j++)
             {s[i][j]=0;
             if(x[i]==y[j])
                      s[i][j]=s[i-1][j-1]+1;
             else
                      s[i][j]=s[i-1][j-1];
             if(s[i][j]<s[i-1][j])
                      s[i][j]=s[i-1][j];
             if(s[i][j]<s[i][j-1])
                      s[i][j]=s[i][j-1];}}
printf("%d\n",s[n][m]);
k=s[n][m];
for(i=n;i>=1;i--)
       {for(j=m;j>=1;j--)
       if(s[i][j]==k)
              {v[k]=y[j];
              d=i-1;
              e=j-1;}}
for(i=k-1;i>=1;i--)
       {while(s[d-1][e]==i)
              d--;
       while(s[d][e-1]==i)
              e--;
       v[i]=x[d];
       d--;
       e--;}
for(i=1;i<=k;i++)
       printf("%d ",v[i]);              
printf("\n");
fclose(stdin);
fclose(stdout);
return 0;}
