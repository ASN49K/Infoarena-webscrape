#include <cstdio>
using namespace std;
int main()
{
freopen("cm1sc.in","r",stdin);
freopen("cm1sc.out","w",stdout);
int n,m,i,max=0,val[10];
scanf("%d %d", &n, &m);
int a[n],b[m];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<m;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
   for(int j=0;j<m;j++)
      if(a[i]==b[j])
      {
      val[max]=a[i];
      ++max;
      }
printf("%d\n", max);
for(i=0;i<max;i++)
printf("%d ",val[i]);
}
