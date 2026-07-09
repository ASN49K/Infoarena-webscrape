#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1030],b[1030];
int v[1030];
int main()
{
	int n,m,i,j,k=0;
	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>a[i];
	for(int j=1;j<=m;j++)
		in>>b[j];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);	
	i=1;
	j=1;
	while(i<=n&&j<=m)
	{
		if(a[i]<b[j]) i++;
		else if(a[i]>b[j]) j++;
		else if(a[i]==b[j])
		{
			v[k++]=a[i];
			i++;
		}
	}
	out<<k<<"\n";
	for(i=0;i<k;i++)
		out<<v[i]<<" ";
	return 0;
}
