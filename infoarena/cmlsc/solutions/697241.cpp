#include<fstream>
using namespace std;
int n, v[100001],sol[100001],prec[100001],p;
int main() {
	ifstream f("scmax.in"); 
	ofstream g("scmax.out");
	int i,j,max;
	f>>n;
	for(i=1;i<=n;i++) f>>v[i];
	sol[n]=1;
	prec[n]=-1;
	max=1;
	p=n;
	for(i=n-1;i>=1;i--) {
		sol[i]=1;
		prec[i]=-1;
		for(j=i+1;j<=n;j++) 
			if(v[i]<v[j] && sol[i]<sol[j]+1) {
				sol[i]=sol[j]+1;
				prec[i]=j;
				if(sol[i]>max) { max=sol[i]; p=i; }
			}
	}
	g<<max<<endl;
	while (p!=-1) {
		g<<v[p]<<" ";
		p=prec[p];
	}
	return 0;
}