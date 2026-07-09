#include<fstream>
using namespace std;
int m,n, a[1025], b[1025], d[1025][1025], sir[1025], bst;
int maxim(int x,int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}
int main(){
	int i, j;
	ifstream f("cmlsc.in");
	ofstream g("cmlcs.out");
	f>>m>>n;
	for(i=1;i<=m;i++){
		f>>a[i];
	}
	for(i=1;i<=n;i++){
		f>>b[i];
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if (a[i] == b[j]){
				d[i][j] = 1 + d[i-1][j-1];
			}
			else{
				d[i][j] = maxim(d[i-1][j], d[i][j-1]);
			}
		}
	}
 
	for (i = m, j = n; i>0 && j>0; ){
		if (a[i] == b[j]){
			sir[++bst] = a[i]; 
			--i; 
			--j;
		}
		else{
			if (d[i-1][j] < d[i][j-1]){
				--j;
			}
			else{
				--i;
			}
		}
	}
 
	g<<bst;
	for (i = bst; i>0; i--){
		g<<sir[i];
	}
 
return 0;
}
