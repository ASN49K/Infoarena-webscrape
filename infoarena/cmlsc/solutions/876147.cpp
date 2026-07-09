#include<stdio.h>
#include <vector>
using namespace std;
#define max(a,b) ((a>b) ? a : b)
vector<int>a,b;
int sol[1024];
int mat[1025][1025];
int main()
{int m,n,i,j,nr,ct=0;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
scanf("%d%d",&m,&n);
for(i=1;i<=m;i++){
      scanf("%d",&nr);
      a.push_back(nr);
}
for(i=1;i<=n;i++){
      scanf("%d",&nr);
      b.push_back(nr);
}

for(i=0;i<=m;i++)
   for(j=0;j<n;j++)
       if(a[i]==b[j])
          mat[i][j]=mat[i-1][j-1] +1;
        else
          mat[i][j]=max(mat[i-1][j],mat[i][j-1]) ;
for(i=m,j=n;i;)
   {
       if(a[i]==b[j])
         {sol[++ct]=a[i];
         i--;
         j--;
         }
        else
          if(mat[i-1][j]<mat[i][j-1])
            j--;
          else
            i--;
   }
printf("%d\n",ct);
for(i=ct;i>0;--i)
   printf("%d ",sol[i]);
return 0;
}
