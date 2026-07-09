#include <fstream>

using namespace std;

#define SIZE 1025

	short a[SIZE];
	short b[SIZE];
	short sir[SIZE];
	short mat[SIZE][SIZE];

int main(){
	int i,j,k;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int m,n;
	
	in>>m>>n;
	
	for(i=1;i<=m;i++){
		in>>a[i];
		mat[i][0] = 0;
	}
	for(i=1;i<=n;i++){
		in>>b[i];
		mat[0][i]=0;
	}
	mat[0][0]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				mat[i][j] = mat[i-1][j-1]+1;
			else
				if(mat[i-1][j]>mat[i][j-1])
					mat[i][j] = mat[i-1][j];
				else
					mat[i][j] = mat[i][j-1];
	i=m;j=n;k=0;
	while(i&&j){
		if(a[i] == b[j]){
			sir[k++] = a[i];
			i--;
			j--;
		}
		else
			if(mat[i-1][j]>mat[i][j-1])
				i--;
			else
				j--;
	}
	out<<k<<endl;
	for(i=k-1;i>=0;i--)
		out<<sir[i]<<" ";
	out<<endl;
	return 0;
}
