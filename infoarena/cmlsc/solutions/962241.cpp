#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N = 1030;
int n,m,a[N],b[N];
int d[N][N],s[N],k;
int maximum(int x,int y){
	if(x>y) return x;
	return y;
}
int take(int i,int j){
	if(i==0 || j==0) return 0;
	if(a[i]==b[j]){
		s[++k]=a[i];
		take(i-1,j-1);
	}
	else{
		if(d[i-1][j]>d[i][j-1]) take(i-1,j);
		else take(i,j-1);
	}
	return 0;
}
int main(){
	int i,j;
	in>>n>>m;
	for(i=1;i<=n;i++) in>>a[i];
	for(i=1;i<=m;i++) in>>b[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=maximum(d[i-1][j],d[i][j-1]);
		}
	}
	out<<d[n][m]<<'\n';
	take(n,m);
	for(i=k;i>0;i--) out<<s[i]<<' ';
	return 0;
}