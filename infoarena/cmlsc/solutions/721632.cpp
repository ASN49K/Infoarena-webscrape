#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1027;
int x[N],y[N];
int a[N][N];

int max(int a,int b)
{
	if(a<b)
		return b;
	return a;
}

void refac(int i, int j)
{
	if(i==0 || j==0)
		return;
	if(x[i]==y[j])
	{
		refac(i-1,j-1);
		out<<x[i]<<" ";
		return;
	}
	if(a[i-1][j]>a[i][j-1])
		refac(i-1,j);
	else
		refac(i,j-1);
}
int main()
{
	int k,p,i,j;
	in>>k>>p;
	for(i=1;i<=k;i++)
		in>>x[i];
	for(i=1;i<=p;i++)
		in>>y[i];
	for(i=1;i<=k;i++)
		for(j=1;j<=p;j++)
		{
			if(x[i]==y[j])
				a[i][j]=1+a[i-1][j-1];
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
		}
	out<<a[k][p]<<"\n";
	refac(k,p);
	return 0;
}