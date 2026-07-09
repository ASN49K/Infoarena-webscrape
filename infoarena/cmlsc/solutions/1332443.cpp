#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;
int d[1026][1026];
int a[1026];
int b[1026];
int sol[1026];
int i,j;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int N,M;
    int counter;
    scanf("%d",&N);
    scanf("%d",&M);
for(int x=1;x<=N;x++)
scanf("%d",&a[x]);
for(int x=1;x<=M;x++)
    scanf("%d",&b[x]);

for(int x=1;x<=N;x++)
    for(int y=1;y<=M;y++)
    if(a[x]==b[y])
    d[x][y]=d[x-1][y-1]+1;
else
    d[x][y]=max(d[x-1][y],d[x][y-1]);
counter=0;
int l=0;

for(i=N,j=M;i;)
{
    if(a[i]==b[j]){
        sol[++counter]=a[i];
        i--;
        j--;

    }
    else if(d[i-1][j]<d[i][j-1])
    j--;
    else
        i--;
}
printf("%d \n",counter);
for(int x=counter;x>=1;x--)
    printf("%d ",sol[x]);
    return 0;
}
