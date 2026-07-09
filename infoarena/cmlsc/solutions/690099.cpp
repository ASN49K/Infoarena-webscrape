#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v[1030],k[1030],mat[1030][1030];
void refac(int i,int j);
int main()
{
	int i,j,l,r,s,m,n,p;
	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>v[i];
	for(j=1;j<=m;j++)
		in>>k[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(v[i]==k[j])
				mat[i][j]=1+mat[i-1][j-1];
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	out<<mat[n][m]<<"\n";
	refac(n,m);
}

void refac(int i,int j)
{
	if(i==0||j==0)return;
	if(v[i]==k[j])
	{
		refac(i-1,j-1);
		out<<v[i]<<" ";
		return;
	}
	if(mat[i-1][j]>mat[i][j-1])
		refac(i-1,j);
	else
		refac(i,j-1);
}