#include<fstream>
using namespace std;
int n,k,x[1024],y[1025],lcs[1026][1026],sol[1024];
int main()
{
	int i,j,p;
	
	ifstream f("cmlsc.in");
	ofstream fout("cmlsc.out");
	
	f>>n>>k;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=k;i++)
		f>>y[i];
	
	f.close();
	for(j=1;j<=k;j++)
	{
		if(x[1]==y[j])
			lcs[1][j]=1;
		else lcs[1][j]=0;
	}
	
	for(i=1;i<=n;i++)
	{
		if(y[1]==x[i])
			lcs[i][1]=1;
		else lcs[i][1]=0;
	}
	
	for(i=1;i<=n;i++)
		for(j=2;j<=k;j++)
		{
			if(x[i]==y[j])
				lcs[i][j]=1+lcs[i-1][j-1];
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	
	fout<<lcs[n][k]<<"\n";
	i=n;j=k;
	p=1;
	while(lcs[i][j]!=0)
	{
		if(x[i]!=y[j])
		{
			if(lcs[i-1][j]>lcs[i][j-1])
				i--;
			else j--;
		}
		else
		{
			sol[p]=x[i];
			p++;
			i--;j--;
		}
	}
	for(i=p-1;i>=1;i--)
		fout<<sol[i]<<" ";
	fout.close();
	return 0;
}

