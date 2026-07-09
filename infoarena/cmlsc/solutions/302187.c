#include<stdio.h>

int a[500],b[500],lung[500][500],subsir[500];
int m,n,i,j,maxim;
int max(int x,int y, int z)
{if(x>y)if(x>z)return x;
       else return z;
       else if(y>z)return y; else return z;

}

int main(void){

freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d %d",&m,&n);

for(i=0; i<m; i++)scanf("%d",&a[i]);

for(i=0; i<n; i++)scanf("%d",&b[i]);

if(a[0]==b[0])lung[0][0]=1; else lung[0][0]=0;

for(i=1; i<m; i++)if(a[i]==b[0])lung[i][0]=1; else lung[i][0]=lung[i-1][0];

for(i=1; i<n; i++)if(a[0]==b[i])lung[0][i]=1; else lung[0][i]=lung[0][i-1];

for(i=1; i<=m-1; i++)
for(j=1; i<=n-1; j++){if(a[i]==b[j]) lung[i][j]=max(lung[i-1][j-1],lung[i-1][j],lung[i][j-1]);
                      else lung[i][j]=max(0,lung[i-1][j],lung[i][j-1]);

                      }

maxim=lung[m-1][n-1];
printf("%d\n",maxim);

i=m-1; j=n-1;
while(i>=0 && j>=0)
{

 if(a[i]==b[j])subsir[maxim]=a[i],maxim--,i--,j--;
else if(i-1>=0 && lung[i][j]==lung[i-1][j]) i--;
else j--;
}

for(i=lung[m-1][n-1]; i>=1; i--)printf("%d ",subsir[i]);

return 0;
}