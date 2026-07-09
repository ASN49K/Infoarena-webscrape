#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1025;

int n,m,a[N],b[N],subsir[N][N],rez[N],nr;

inline int max(int x,int y){
	return x>y ? x:y;
}

int main(){
	int i,j;
	in>>n>>m;
	for(i=1;i<=n;i++){
		in>>a[i];
	}
	for(j=1;j<=m;j++){
		in>>b[j];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j]){
				subsir[i][j]=subsir[i-1][j-1]+1;
			}
			else{
				subsir[i][j]=max(subsir[i][j-1],subsir[i-1][j]);
			}
		}
	}
	i=n;
	j=m;
	while(i>0 && j>0){
		if(a[i]==b[j]){
			rez[++nr]=a[i];
			i--;
			j--;
		}
		else{
			if(subsir[i][j-1]>subsir[i-1][j]){
				j--;
			}
			else{
				i--;
			}
		}
	}
	out<<nr<<"\n";
	for(i=nr;i>=1;i--){
		out<<rez[i]<<" ";
	}
	return 0;
}