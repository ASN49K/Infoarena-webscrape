#include<fstream>
#define dmax 1027
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

short int n,m,x[dmax],y[dmax],mat[dmax][dmax],z[dmax],k;

int main()
{	short int i,j;

	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>x[i];
	for(i=1;i<=m;i++)
		in>>y[i];
	
	in.close();
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	if(x[i]==y[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else 
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	
	i=n , j=m;
	
	while(i && j)
	{	if(x[i]==y[j])
		{	z[k++]=x[i];
			i--; 
			j--;
		}
		else if(mat[i-1][j] >= mat[i][j-1])
			i--;
		else if(mat[i][j-1] > mat[i-1][j])
			j--;
	}	
	
	out<<mat[n][m]<<'\n';
	for(i=k-1;i>=0;i--)
		out<<z[i]<<" ";
	
	out.close();
	return 0;
}	