#include<iostream>
#include<fstream>
int a[100000],c,i,j,t;
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	f>>t;
	for(i=1;i<=2*t;i++)
		f>>a[i];
	for(i=1;i<=2*t;i+=2)
	{c=a[i]%a[i+1];
while(c!=0)
			{c=a[i]%a[i+1];
 a[i]=a[i+1];
 a[i+1]=c;
			}
if(a[i]==1){g<<0;g<<endl;}
else {g<<a[i];
		g<<endl;}}
f.close();
g.close();
return 0;
}
