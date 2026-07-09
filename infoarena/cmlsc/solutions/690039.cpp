#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1030;

int n,m,a[N][N],x[N],y[N];

inline int maxim(int x,int y)
{
	return x > y ? x : y;
}

void citire()
{
	in>>m>>n;
	for(int i=1;i<=m;++i)
		in>>x[i];
	for(int j=1;j<=n;++j)
		in>>y[j];
}

void refac(int i,int j)
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

void work()
{
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(x[i]==y[j])
				a[i][j]=1+a[i-1][j-1];
			else
				a[i][j]=maxim(a[i-1][j],a[i][j-1]);
	out<<a[m][n]<<"\n";
	refac(m,n);
}


int main()
{
	citire();
	work();
	return 0;
}
