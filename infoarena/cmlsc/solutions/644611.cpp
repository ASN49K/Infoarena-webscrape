#include<iostream.h>
int main()
{
	int lis[100],n,u,j,max,x[100];
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>x[i];
	lis[n]=1;
	for(i=n-1;i>=n;i--)
	{
		max=0;
		for(j=i+1;j<=n;j++)
		{
			if(max<lis[j]&&x[i]<x[j])
				max=lis[j];
		}
		lis[i]=max+1;
	}
	max=lis[i];
	for(i=2;i<=n;i++)
		if(max<lis[i])
			max=lis[i];
		cout<<max<<'\n';
		for(int t=1;t<=n;t++)
			cout<<lis[t];
		return 0;
}