#include <cstdio>
#define max_l 1050
#include <algorithm>

using namespace std;

int a[max_l],b[max_l];
int lcs[max_l][max_l];
int n,m;

void read(int a[],int m){
  for(int i=1;i<=m;++i)
     scanf("%d",&a[i]);
}

void lcs_len(int x[],int y[]){
  int i,j;
  for(i=0;i<=m;++i)lcs[i][0]=0;
  for(j=0;j<=n;++j)lcs[0][j]=0;
  
  for(i=1;i<=m;++i){
     for(j=1;j<=n;++j){
         if(x[i] == y[j])lcs[i][j]=lcs[i-1][j-1]+1;
         else
            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
     }
  }
}

void btr(int x[],int y[],int i,int j){
   if(!i || !j)
      return;
   if(x[i] == y[j]){
      btr(x,y,i-1,j-1);
      printf("%d ",x[i]);
      return;
     }
   if(lcs[i-1][j]<lcs[i][j-1]){
      btr(x,y,i,j-1);
      return;
   }
   btr(x,y,i-1,j);
}

int main(void){
   freopen("cmlsc.in","r",stdin);
   
   scanf("%d%d",&m,&n);

   read(a,m);
   read(b,n);
   
   lcs_len(a,b);
   freopen("cmlsc.out","w",stdout);
   printf("%d\n",lcs[m][n]);
   
   btr(a,b,m,n);
}