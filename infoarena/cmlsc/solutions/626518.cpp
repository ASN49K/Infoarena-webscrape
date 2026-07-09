#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
	int n,m,a[2000],b[2000],i,j,k;
	fin>>n>>m;
	for(i=1;i<=n;i++)fin>>a[i];
	for(j=1;j<=m;j++)fin>>b[j];
	k=1;
	for(i=1;i<=n;i++)
	{
		for(j=k;j<=m;j++)
			if(a[i]==b[j]){
							fout<<a[i]<<" ";
							k=j;
			}
	}
fin.close();
fout.close();
return 0;
	}
	