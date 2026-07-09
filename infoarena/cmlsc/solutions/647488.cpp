#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1025],y[1025],m,n,lcs[1025][1025],i,j,lala[1025],l;
int main()
{	
	fin>>n>>m;
	for(i=1;i<=n;i++) fin>>x[i];
	for(i=1;i<=m;i++) fin>>y[i];


	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);


	i=n; j=m;
	l=lcs[n][m];

	while(i&&j) 
	{
		if(x[i]==y[j]) 
		{
			lala[l]=x[i];
			l--;
			i--;
			j--;
		}	
		else 
			if(lcs[i][j-1]>=lcs[i-1][j]) j--;
		else i--;
	}
	fout<<lcs[n][m]<<endl;
	for(i=1;i<=lcs[n][m];i++)
	fout<<lala[i]<<" ";
	return 0;
}

