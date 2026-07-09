#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int s[1024],t[1024],m,n,a[1024][1024],sol[1024],nr=0;
int max(int a, int b)
{
	if(a<b)
		return b;
	else return a;	
}
	
int main()
{
	int i,j;
	cin>>m;
	cin>>n;
	for(i=1;i<=m;i++)
		cin>>s[i];
	for(i=1;i<=n;i++)
		cin>>t[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(s[i]!=t[j])
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			if(s[i]==t[j])
				a[i][j]=1+a[i-1][j-1];
		}
	cout<<a[m][n]<<"\n";
	i=m;
	j=n;
	while(i!=1&&j!=1)
	{
		if(s[i]==t[j])
		{
			sol[++nr]=s[i];
			--i; --j;
			continue;
		}
		if(a[i-1][j]>=a[i][j-1])
			--i;
		else
			--j;
	}
	for(i=nr;i>=1;i--)
		cout<<sol[i]<<" ";
	return 0;
}
