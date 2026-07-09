#include<fstream>
using namespace std;
int main()
{
	ifstream g("cmlsc.in");ofstream h("cmlsc.out");
	int m,n,i,j,a[1025],b[1025],MAX=0,c[1025];
	g>>n>>m;
	for(i=1;i<=n;i++)
		g>>a[i];
	for(i=1;i<=m;i++)
		g>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
			{
				MAX++;
				c[MAX]=a[i];
				break;
			}
	h<<MAX<<"\n";
	for(i=1;i<=MAX;i++)
		h<<c[i]<<" ";
}