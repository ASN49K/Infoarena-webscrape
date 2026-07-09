#include <iostream.h>
#include <fstream.h>
int main()
{
short int a[1024],b[1024],c[1024],m,n,i,j,s=0;
ifstream citire("cmlsc.in");
ofstream scriere("cmlsc.out");
citire>>n;
citire>>m;
for (i=1;i<=n;i++)
citire>>a[i];
for (j=1;j<=m;j++)
citire>>b[j];
cout<<n<<"\n"<<m;
for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	{
	      if (a[i]==b[j])
	      {
		s++;
		 c[s]=a[i];
	      }
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