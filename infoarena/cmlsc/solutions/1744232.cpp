#include <cstdio>
#include <stack>
using namespace std;
int z[1025][1025];

int main()
{freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 int n,m,i,j,v[1025],w[1025];
 scanf("%d%d",&n,&m);
 if(n>m){n=n^m;m=n^m;n=n^m;for(i=1;i<=m;i++)scanf("%d",w+i);for(i=1;i<=n;i++)scanf("%d",v+i); }
else{
 for(i=1;i<=n;i++)scanf("%d",v+i);
 for(i=1;i<=m;i++)scanf("%d",w+i);
}

 for(i=1;i<=n;i++)
 {
     for(j=1;j<=m;j++)
     {
         if(v[i]==w[j])
            {
                z[i][j]=z[i-1][j-1]+1;
            }
         else z[i][j]=z[i-1][j]>z[i][j-1]? z[i-1][j]:z[i][j-1];
     }
 }
/*
  for(i=1;i<=n;i++)
 {
     for(j=1;j<=m;j++)
     {
       printf("%d ",z[i][j]);
     }printf("\n");
 }*/

 printf("%d\n",z[n][m]);
 i=n;j=m;
 stack <int> stiv;
 while(z[i][j])
 {
     if(z[i][j]==z[i][j-1])j--;
     else if(z[i][j]==z[i-1][j])i--;
     else{stiv.push(v[i]);i--;j--; }
 }

 while(!stiv.empty())
 {
     printf("%d ",stiv.top() );
     stiv.pop();
 }




    return 0;
}
