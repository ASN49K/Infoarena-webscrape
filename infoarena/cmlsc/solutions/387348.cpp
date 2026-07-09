#include <fstream>

#define MAX 1025

using namespace std;
int s1[MAX],s2[MAX],c[MAX][MAX],res[MAX];
int n,m;

int main(){
	fstream fin("cmlsc.in",ios::in);
	fstream fout("cmlsc.out",ios::out);
	fin>>n>>m;
	for(int i=0;i<n;i++){
		fin>>s1[i];
	}
	for(int i=0;i<m;i++){
		fin>>s2[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				c[i][j]=c[i-1][j-1]+1;
			}else{
				c[i][j]=(c[i][j-1]>c[i-1][j])?c[i][j-1]:c[i-1][j];
			}
		}
	}
	fout<<c[n][m]<<endl;
	int a=n,b=m,cnt=0;
	while(a||b){
		if(a&&b&&s1[a-1]==s2[b-1]){
			res[c[n][m]-(++cnt)]=s1[a-1];
			a--,b--;
		}else if(a&&c[a][b]==c[a-1][b]){
			a--;
		}else if(b&&c[a][b]==c[a][b-1]){
			b--;
		}
	}
	for(int i=0;i<cnt;i++){
		fout<<res[i]<<" ";
	}
	fin.close();
	fout.close();
}