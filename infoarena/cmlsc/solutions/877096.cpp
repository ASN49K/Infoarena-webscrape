#include<stdio.h>
#include <vector>
using namespace std;
#define max(a,b) ((a>b) ? a : b)
vector<int>a,b;
int sol[1025];
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

for(i=0;i<m;i++)
   for(j=0;j<n;j++)
       if(a[i]==b[j])
          mat[i+1][j+1]=mat[i][j] +1;
        else
          mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]) ;
for(i=m-1,j=n-1;i>=0;)
   {
       if(a[i]==b[j])
         {sol[++ct]=a[i];
         i--;
         j--;
         }
        else
          if(mat[i][j+1]<mat[i+1][j])
            j--;
          else
            i--;
   }
printf("%d\n",ct);
for(i=ct;i>0;--i)
   printf("%d ",sol[i]);
return 0;
}
