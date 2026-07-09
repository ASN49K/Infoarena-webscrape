#include<fstream>
#include<algorithm>
#define nmax 1050
using namespace std;
int a[nmax],b[nmax],m[nmax][nmax],na,nb,v[nmax],nr;
int main(){
	ifstream in("cmlsc.in"); ofstream out("cmlsc.out");
	in>>na>>nb;
	for(int i=1;i<=na;++i) in>>a[i];
	for(int i=1;i<=nb;++i) in>>b[i];
	for(int i=1;i<=na;++i){
		for(int j=1;j<=nb;++j){
			if(a[i]==b[j]) m[i][j]=m[i-1][j-1]+1; 
			else m[i][j]=max(m[i-1][j], m[i][j-1]);
		}
	}
	for(int i=na,j=nb;i;){
		if(a[i]==b[j]) v[++nr]=a[i],--i,--j;
		else if (m[i-1][j]<m[i][j-1]) --j;
		else --i;
	}
	out<<nr<<'\n';
	for(int i=nr;i>=1;--i) out<<v[i]<<' '; out<<'\n';
	out.close(); return 0;
}