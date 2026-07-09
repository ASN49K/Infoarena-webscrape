#include <fstream>
#include <stdio.h>

using namespace std;
int a[1025][1025];
int li[1025];
int ci[1025];
int subs[1025];
int main()
{int m,n,i,j,k=0;
ifstream in("cmlsc.in");
freopen("cmlsc.out", "w", stdout);
in>>m>>n;
for(i=1;i<=m;i++)
    in>>li[i];
for(i=1;i<=n;i++)
    in>>ci[i];
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
{if(li[i]==ci[j]) a[i][j]=a[i-1][j-1]+1;
else {if(a[i-1][j]>=a[i][j-1]) a[i][j]=a[i-1][j];
      if(a[i-1][j]<=a[i][j-1]) a[i][j]=a[i][j-1];
     }}
i=m;
j=n;
while(i>0)
{
    if(li[i]==ci[j]) {subs[++k]=ci[j];
    j--;
    i--;}
   else{if(a[i-1][j]<=a[i][j-1]) j--;
    if(a[i-1][j]>=a[i][j-1]) i--;}
}
printf("%d\n", k);
    for (i = k; i; --i)
        printf("%d ", subs[i]);
    in.close();
    return 0;
}
