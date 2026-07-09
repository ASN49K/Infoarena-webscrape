#include<fstream>
using namespace std;
short a[1025],b[1025],m,n,s[1025][1025],i,j,sol[1025*1025],k;
int main()
{
	ifstream fcin("cmlsc.in");
	ofstream fcout("cmlsc.out");
	fcin>>n>>m;
	for(i=1;i<=n;i++)
		fcin>>a[i];
	for(i=1;i<=m;i++)
		fcin>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
			{
				s[i][j]=s[i-1][j-1]+1;
				sol[++k]=a[i];
			}
			else
				if(s[i-1][j]>s[i][j-1])
					s[i][j]=s[i-1][j];
				else
					s[i][j]=s[i][j-1];
	fcout<<s[n][m]<<"\n";
	for(i=1;i<=k;i++)
		fcout<<sol[i]<<" ";
	return 0;
}
