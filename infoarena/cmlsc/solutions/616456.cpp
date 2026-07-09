#include<fstream>
using namespace std;
int main(){
	int m,n,x[1024],y[1024],i,j,p,vector[1024],k,vec[1024],max,var;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>x[i];
	for(i=1;i<=n;i++)
		f>>y[i];
	f.close();
	p=1;
	max=0;
	var=1;
	for(i=1;i<=m;i++){
		k=0;
		for(j=1;j<=n&&k==0;j++)
			if(x[i]==y[j]){ k++;
			}
				if(k!=0){
			vector[p]=x[i];
			p++;
		}
		if(j>=n){
			if(p-1>max){ max=p-1;
				for(var=1;var<p;var++)
					vec[var]=vector[var];
			}
			p=0;
		}

	}
	g<<max<<'\n';;
	for(i=1;i<=max;i++)
		g<<vec[i]<<" ";
	g<<'\n';
	g.close();
	return 0;}
