#include<iostream.h>
#include<fstream.h>
main()
{
ifstream f("date.in");

int x[100], n, i, ap[100], j, k, max;

f>>n;
for(i=1;i<=n;i++)
	f>>x[i];

for(i=1;i<=n;i++)
	{
	cout<<x[i]<<" ";
	k=0;
	max=0;
	for(j=1;j<i;j++)
		if(x[j]<x[i]&&x[j]>max)
			{
			max=x[j];
			k++;
			}
	ap[i]=k+1;
	}
max=ap[1];
cout<<endl;
for(i=1;i<=n;i++)
	{
	cout<<ap[i]<<" ";
	if(ap[i]>max)
		max=ap[i];
	}
cout<<endl<<max<<" ";
}
