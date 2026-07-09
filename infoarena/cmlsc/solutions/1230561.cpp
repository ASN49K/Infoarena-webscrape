#include <fstream>
#include <string>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

#define MAX 1024

#define max(x,y) (x > y) ? x : y
#define r(i,x,y) for(int i = x; i < y; i++)
#define br(i,x,y) for(int i = y - 1; i >= x; i--)
	int n, m;
	int a[MAX], b[MAX];
	int d[MAX][MAX];
	int v[MAX], count = 0;

void maxim(int i,int j){
		//g<<"i:"<<i<<" a[i]:"<<a[i]<<"     ------     ";
		//g<<"j:"<<j<<" b[j]:"<<b[j]<<"\n";
		if(i < 0 || j < 0) return;
		else if(a[i] == b[j]) {v[count] = a[i]; count++; maxim(i-1,j-1);}
		else {
			if(d[i + 1][j] > d[i][j + 1]) maxim(i,j-1);
			else maxim(i-1,j);
		}
}

int main(){

	f>>n;
	f>>m;

	d[n][0] = 0;
	d[0][m] = 0;


	r(i,0,n) {f>>a[i]; /*g<<a[i]<<" ";*/ d[i][0] = 0;}
	//g<<"\n";
	r(j,0,m) {f>>b[j]; /*g<<b[j]<<" ";*/ d[0][j] = 0;}
	//g<<"\n";

	r(i,0,n){
		r(j,0,m){
			if(a[i] == b[j]) d[i + 1][j + 1] = d[i][j] + 1;
			else d[i + 1][j + 1] = max(d[i][j + 1],d[i + 1][j]);
		}
	}

	/*r(i,0,n + 1){
		r(j,0,m + 1){
			g<<d[i][j]<<" ";
		}
		g<<"\n";
	}*/
	maxim(n - 1,m - 1);
	g<<count<<"\n";
	br(i,0,count) g<<v[i]<<" ";

	return 0;
}
