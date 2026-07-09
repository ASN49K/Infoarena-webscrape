#include<fstream>
#include<iostream>
using namespace std;
int a[100],b[100],c[100][100],n,m;

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
	i=n;j=m;
	int s=0;
	while(i)
	{
		if(a[i]==b[j])
		{
			out<<a[i]<<" ";
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
	in.close();
	out.close();
	return 0;
}