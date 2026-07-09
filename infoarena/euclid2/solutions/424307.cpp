#include<iostream>
#include<fstream>
int a[100000][2],c,i,j,t;
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
		for(j=1;j<=2;j++)
			f>>a[i][j];
	for(i=1;i<=t;i++)
	{c=a[i][1]%a[i][2];
while(c!=0)
			{c=a[i][1]%a[i][2];
 a[i][1]=a[i][2];
 a[i][2]=c;
			}
if(a[i][1]==1)g<<0<<endl;
else g<<a[i][1]<<endl;}
f.close();
g.close();
return 0;
}
