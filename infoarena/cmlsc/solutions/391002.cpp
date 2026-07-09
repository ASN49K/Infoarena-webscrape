#include<stdio.h>
#define maxn 1024
int D[maxn][maxn];

int max(int a,int b)
{if(a>b)
return a;
return b;}

int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
int N,M,A[maxn],B[maxn],i,j,sol[maxn];
scanf("%d %d",&M,&N);
for(i=1;i<=M;i++)
  scanf("%d",&A[i]);
for(i=1;i<=N;i++)
  scanf("%d",&B[i]);

for(i=1;i<=M;i++)
  for(j=1;j<=N;j++)
    if(A[i]==B[j])
      D[i][j]=1+D[i-1][j-1];
    else 
      D[i][j]=max(D[i][j-1],D[i-1][j]);
      
int t=0;
i=M;j=N;
while(i>0 && j>0)
if(A[i]==B[j])
sol[++t]=A[i],i--,j--;
else if(D[i-1][j]<D[i][j-1])
j--;
else 
i--;
//for(i=1;i<=M;i++)
//{for(j=1;j<=N;j++)
//printf("%d",D[i][j]);
//printf("\n");}
printf("%d\n",t);
for(i=t;i>0;i--)
printf("%d ",sol[i]);
fclose(stdin);
fclose(stdout);
return 0;
}