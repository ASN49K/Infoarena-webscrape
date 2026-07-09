#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1024+1;

int m,n;
int a[MAX], b[MAX];
int d[MAX][MAX],sol[MAX];

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");


	in >> m >> n;
	a[0]=0; b[0]=0; d[0][0]=0;
	for(int i=1;i<=m;i++){ in >> a[i]; d[i][0]=0; }
	for(int j=1;j<=n;j++){ in >> b[j]; d[0][j]=0; }

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if (a[i]==b[j]){
				d[i][j]=d[i-1][j-1]+1;
			}else{
				d[i][j]=d[i][j-1]>d[i-1][j]?d[i][j-1]:d[i-1][j];
			}
			out<<"("<<d[i][j]<<")";
		}
		out<<endl;
	}

	out << d[m][n] << "\n";

	int k=d[m][n];
	int i=m, j=n;
	while(k>0){
		while(d[i][j-1]==k) --j;
		while(d[i-1][j]==k) --i;
		sol[k-1]=a[i];
		--k; --i; --j;
	}
	for(int k=0;k<d[m][n];k++){
		out << sol[k] <<" ";
	}
	out << "\n";

	in.close();
	out.close();
	return 0;
}
