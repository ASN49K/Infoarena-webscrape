#include<fstream>
using namespace std;
long i,j,a[1050][1050],v1[1000100],v2[1000100],m,n,k,v[1000100];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>v1[i];
	for(j=1;j<=m;j++)
		fin>>v2[j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(v2[i]!=v1[j])
			{
				if(a[i-1][j]>=a[i][j-1])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i][j-1];
			}
			else
				a[i][j]=a[i-1][j-1]+1;
i=m;
j=n;
int s=a[m][n];
fout<<s<<'\n';
while(s)
{
		if(v1[j]==v2[i])
		{
			k++;
			--s;
			v[k]=v1[j];
			i--;
			j--;
		}
		else
	             if(a[i-1][j]==s)
			i--;
				 else
			j--;		 
}	
for(i=k;i>=1;i--)
	fout<<v[i]<<" ";
return 0;
}	
			