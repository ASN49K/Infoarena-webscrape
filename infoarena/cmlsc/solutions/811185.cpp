#include <fstream>
#define Nmax 1030
#define Mmax 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[Nmax];
int b[Mmax];
int lcs[Nmax][Mmax];//longest common subsequence
int sol[Nmax];
int soli=0;

void citire();
void pd();
int maxim(int k, int l);
void afisare();

void citire(){
	int i,j;
	fin>>n;
	fin>>m;
	for(i=0;i<n;i++)
		fin>>a[i];
	for(j=0;j<m;j++)
		fin>>b[j];
}

void pd(){
	int i,j;
	for(i=0;i<=n;i++)
		lcs[i][m]=0;
	for(j=0;j<m;j++)
		lcs[n][j]=0;//cazurile cele mai mici
	for(i=n-1;i>=0;i--)
		for(j=m-1;j>=0;j--)
			if(a[i]==b[j]){
				lcs[i][j]=1+lcs[i+1][j+1];
				sol[soli]=a[i];
				soli++;
			}
			else
				lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
}

int maxim(int k, int l){
	if(k>l)
		return k;
	return l;
}

void afisare(){
	fout<<lcs[0][0]<<'\n';
	soli--;
	while(soli>=0){
		fout<<sol[soli]<<' ';
		soli--;
	}
}
int main(){
	citire();
	pd();
	afisare();
	fout.close();
	return 0;
}