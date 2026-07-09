#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,d[1025][1025],a[1025],b[1025],n1,n2,j,nr,sol[1025];
int main(){
	f>>n1>>n2;
	for (i=1;i<=n1;i++)
		f>>a[i];
	for (i=1;i<=n2;i++)
		f>>b[i];
	for (i=1;i<=n1;i++)
		for (j=1;j<=n2;j++){
			if (a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else{
				if (d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else
					d[i][j]=d[i][j-1];
			}
		}
	g<<d[n1][n2]<<'\n';
	int i=n1;
	int j=n2;
	while(j!=0&&i!=0){
		if(a[i]==b[j]){
			sol[++nr]=a[i];
			i--;
			j--;
		}
		else{
			if (d[i-1][j]>d[i][j-1])
				i--;
			else
				j--;
		}
	}
	for(i=nr;i>=1;i--){
		g<<sol[i]<<' ';
	}
    return 0;
}
