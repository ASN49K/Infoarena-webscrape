#include<fstream>
#define Max(a,b) a>b?a:b
using namespace std;

ofstream fout("cmlsc.out");

int n,m,a[1026],b[1026],t[1026][1026],cml;

void read();
void doit();
void write(int x,int y);

int main() {
	read();
	doit(); 
	cml=t[n][m]; fout<<cml<<'\n';
	write(n,m);
	return 0;
}

void read() {
	int i;
	ifstream fin("cmlsc.in");
	fin>>n>>m;
	for (i=1;i<=n;i++) fin>>a[i];
	for (i=1;i<=m;i++) fin>>b[i];
	fin.close();
}

void doit() {
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i]==b[j]) t[i][j]=t[i-1][j-1]+1;
			else t[i][j]=Max(t[i-1][j],t[i][j-1]);
}

void write(int x,int y) {
	if (x==0 || y==0) return;
	if (a[x]==b[y]) {
		write(x-1,y-1);
		fout<<a[x]<<' ';
	}
	else if (t[x][y-1]>t[x-1][y]) write(x,y-1);
		 else write(x-1,y);
}