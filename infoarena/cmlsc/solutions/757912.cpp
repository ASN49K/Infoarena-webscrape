#include <cstdio>
using namespace std;
int main()
{
freopen("cmlsc.in","r",stdin);
int n,m,i,max=0,val[256];
scanf("%d %d", &n, &m);
int a[256],b[256];
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
fclose(stdin);
freopen("cmlsc.out", "w", stdout);
printf("%d\n", max);
for(i=0;i<max;i++)
printf("%d ",val[i]);
fclose(stdout);
}
