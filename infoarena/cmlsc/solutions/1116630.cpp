#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[1024],b[1024],c[1024][1024],sir[1024];

int maxim(int x, int y){
	if (x>=y)
		return x;
	else
		return y;
}

int main() {
	in>>n>>m;
	
	for (int i=1;i<=n;i++)
		in>>a[i];
	for (int i=1;i<=m;i++)
		in>>b[i];

	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				c[i][j]=maxim(c[i-1][j],c[i][j-1]);
	
	int i=n;
	int j=m;
	int best=c[n][m];
	while(i>0 && j>0){
		if (a[i]==b[j]){
			sir[best]=a[i];
			best--;
		}
		else
			if (c[i-1][j]<c[i][j-1])
				j--;
			else
				i--;
		out<<best<<"\n";
		for (int i=0;i<best;i++)
			out<<sir[i]<<" ";
	
	}
	return 0;
}



