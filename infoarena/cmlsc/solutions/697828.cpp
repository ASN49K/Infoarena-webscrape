#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream o("cmlsc.out");
int main()
{
	int i,n,m,a[1030],b[1030],x,k=0;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	i=1;int j;
	while(f>>x)
	{
		j=i;
		for(;i<=n;i++)
			if(a[i]==x)
				{
					b[k]=x;
					k++;
					i=n+i+2;
				}
		if(i>n+1)
			i=i-n-3;
		else
			i=j;
	}
	o<<k<<"\n";
			for(i=0;i<k;i++)
				o<<b[i]<<" ";
}