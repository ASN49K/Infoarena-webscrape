#include <fstream>
using namespace std;

ifstream r("cmlsc.in");
ofstream w("cmlsc.out");

unsigned n,m,i,j,a[1025],b[1025],c[1025][1025],afis[1025],nrafis;

#define MAX(a,b) ((a) > (b) ? (a) : (b))

unsigned LCSLenghth()
{
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) c[i][j] = c[i-1][j-1]+1;
			else c[i][j] = MAX(c[i-1][j],c[i][j-1]);

	return c[n][m];
}

unsigned backtrack(unsigned i,unsigned j)
{
	if(i==0 || j==0) return 0;
	else
		if(a[i]==b[j]) { afis[++nrafis]=a[i]; return backtrack(i-1,j-1);   }
		else
			if(c[i-1][j]>c[i][j-1]) return backtrack(i-1,j);
			else return backtrack(i,j-1);
}



int main()
{
	r>>n>>m;
	for(i=1;i<=n;i++) r>>a[i]; for(i=1;i<=m;i++) r>>b[i];
	w<<LCSLenghth()<<"\n";
	backtrack(n,m);
	for(i=nrafis;i>0;i--) w<<afis[i]<<" ";
	r.close(); w.close();
	return 0;
}

