#include <fstream.h>
#include <iostream.h>
int n,i,x,y;
int main(){
	ifstream fin("euclid2.in");
	fin>>n;
	int a[n+1][3];
	for(a[0][0]=1;a[0][0]<=n;a[0][0]++){
		fin>>a[a[0][0]][1];
		fin>>a[a[0][0]][2];
	}
	fin.close();
	ofstream fout("euclid2.out");
	for(i=1;i<=n;i++){
		x=a[i][1], y=a[i][2];
		while(x!=y){
		if(x>y)
			x-=y;
		else
			y-=x;
		}
		fout<<x<<'\n';
	}
	fout.close();
	return 0;
}
