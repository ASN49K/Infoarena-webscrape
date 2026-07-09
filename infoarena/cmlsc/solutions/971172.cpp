#include<fstream>
#include<iostream>
using namespace std;
int a[1000],b[1000],c[1000][1000], sol[1000],n,m;

int main()
{
	int i,j;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	in>>n>>m;
	for( i=1;i<=n;i++)
		in>>a[i];
	for( i=1;i<=m;i++)
		in>>b[i];
	
	for( i=1;i<=n;i++)
		for( j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
		}
		
	for( i=1;i<=n;i++)
	{
		for( j=1;j<=m;j++)
			cout<<c[i][j]<<" ";
		cout<<"\n";
	}
		
	i=n;j=m;
	int s=1;
	while(i)
	{
		if(a[i]==b[j])
		{
			sol[s]=a[i];
			i--; j--;
			s++;
		}
		else
		{
			if(c[i][j-1]>c[i-1][j])
				j--;
			else
				i--;
		}
	}
	out<<s-1<<"\n";
	for(i=s-1;i>=1;i--)
		out<<sol[i]<<" ";
	in.close();
	out.close();
	return 0;
}