#include<fstream>
#include<algorithm>
#include<cmath>

using namespace std;
	
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
	
int n, m, a[1030], b[1030], d[1030][1030], s[1030], f;
	
int main(){
	cin>>m>>n;
	int i, j;

	for(i=1;i<=m;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	
	for(int i=0; i<=n; i++) d[0][i]=0;
	for(int i=0; i<=m; i++) d[i][0]=0;
	
	
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}

	for(i=m,j=n; i; ){
		if(a[i]==b[j])s[++f]=a[i], --i,--j;
		else if(d[i-1][j]<d[i][j-1]) j--;
		else i--;
	}
	
	
	cout<<f<<"\n";
	

	while(f--)cout<<s[f+1]<<" ";
	
	
	return 0;
}
