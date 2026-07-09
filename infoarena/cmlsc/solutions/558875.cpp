#include<fstream>
#define dmax 1026
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,x[dmax],y[dmax],mat[dmax][dmax],s[dmax],nr;

int main()
{	
	int i,j;
	
	in>>n>>m;
	
	for(i=1;i<=n;i++)
		in>>x[i];
	for(i=1;i<=m;i++)
		in>>y[i];
	in.close();
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i] == y[j])
				mat[i][j] = mat[i-1][j-1]+1;
			else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
	
	i=n, j=m;
	
	while(i && j)
	{	if(x[i] == y[j])
		{	nr++;
			s[nr]=x[i];
			i--, j--;
		}
		else if(mat[i-1][j] <= mat[i][j-1])
			j--;
		else if(mat[i-1][j] > mat[i][j-1])
			i--;	
	}	
	
	out<<nr<<'\n';
	
	for(i=nr; i>=1; i--)
		out<<s[i]<<" ";
	
	out.close();
	return 0;
}	