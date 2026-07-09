#include<fstream>
#define Nmax 1025
using namespace std;
int a[Nmax],b[Nmax],L[Nmax][Nmax],N,M,sol[Nmax],cnt;
int main()
{
	ifstream f("cmlsc.in");
	f>>M>>N;
	int i,j;
	for(i=1;i<=M;++i)
		f>>a[i];
	for(i=1;i<=N;++i)
		f>>b[i];
	for(i=1;i<=M;++i)
		for(j=1;j<=N;++j)
			if(a[i]==b[j])
				L[i][j] = 1+L[i-1][j-1];
			else L[i][j] = max(L[i-1][j],L[i][j-1]);
	int var=L[M][N],li=M,lj=N;
	while(var)
	{
		i=li;
		j=lj;
		for(i=li;i>0;--i)
			for(j=lj;j>0&&L[i][j] == var;--j)
				if(a[i] == b[j])
				{
					sol[var] = a[i];
					--var;
					li = i-1;
					lj = j-1;
					i=j=0;
				}
	}
	ofstream g("cmlsc.out");
	g<<L[M][N]<<"\n";
	for(i=1;i<=L[M][N];++i)
		g<<sol[i]<<" ";
	g.close();
	return 0;
}
