#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;
int d[1000][1000];
int a[1000];
int b[1000];
int sol[1000];
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
counter=1;
int l=0;
for(int x=1;x<=N;x++)
    for(int y=1;y<=M;y++)
    if(d[x][y]==counter){
    sol[counter++]=a[x];
    l++;

}
printf("%d \n",l);
for(int x=1;x<counter;x++)
    printf("%d ",sol[x]);
    return 0;
}
