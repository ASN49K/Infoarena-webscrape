#include<fstream>
using namespace std;
int M[1026][1026],v[1025];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int n,m,i,j;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	in>>n>>m;
	for(j=2;j<=n+1;j++)
		in>>M[0][j];
	for(i=2;i<=m+1;i++)
		in>>M[i][0];
	for(i=2;i<=m+1;i++)
		for(j=2;j<=n+1;j++)
		{
			if(M[i][0]==M[0][j])
				M[i][j]=M[i-1][j-1]+1;
			else
				M[i][j]=max(M[i][j-1],M[i-1][j]);
		}
	out<<M[m+1][n+1]<<'\n';
	i=m+1;
	j=n+1;
	int k=1;
	while(M[i][j]!=0)
	{
		if(M[0][j]==M[i][0])
			{i--;j--;v[k++]=M[0][j+1];}
		else if(M[i-1][j]>M[i][j-1])
			i--;
		else
			j--;
	}
	for(k=k-1;k>0;k--)
		out<<v[k]<<" ";
	in.close();
	out.close();
	return 0;
}
