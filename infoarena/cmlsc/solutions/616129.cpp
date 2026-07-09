#include<fstream>
using namespace std;
int main(){
	int m,n,x[1024],y[1024],i,j,p,vector[1024],k;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>x[i];
	for(i=1;i<=n;i++)
		f>>y[i];
	f.close();
	p=1;
	for(i=1;i<=m;i++){
		k=0;
		for(j=1;j<=n&&k==0;j++)
			if(x[i]==y[j]){ k++;
			}
		if(k!=0){
			vector[p]=x[i];
			p++;
		}
	}
	g<<p-1<<'\n';;
	for(i=1;i<p;i++)
		g<<vector[i]<<" ";
	g<<'\n';
	g.close();
	return 0;}
