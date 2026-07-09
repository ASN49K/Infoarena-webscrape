#include <iostream.h>
#include <fstream.h>
int main()
{
int a[100],b[100],c[100],m,n,i,j,s=1;
ifstream citire("cmlsc.in");
ofstream scriere("cmlsc.out");
citire>>m;
citire>>n;
for (i=1;i<=n;i++)
citire>>a[i];
for (j=1;j<=m;j++)
citire>>b[j];
for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	      if (a[i]==b[j])
	      {
		 c[s]=a[i];
		 s++;
	      }
scriere<<s;
scriere<<"\n";
for (i=1;i<=s;i++)
{
	scriere<<c[i];
	scriere<<" ";
}
return 0;
}