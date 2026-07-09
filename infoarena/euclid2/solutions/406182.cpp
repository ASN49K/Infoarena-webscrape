#include <fstream.h>
#include <iostream.h>
int n,a[100001][3],i;
void cit(){
	ifstream fin("euclid2.in");
	fin>>n;
	for(a[0][0]=1;a[0][0]<=n;a[0][0]++){
		fin>>a[a[0][0]][1];
		fin>>a[a[0][0]][2];
	}
	fin.close();
}
int ver(int x,int y){
	while(x!=y){
		if(x>y)
			x-=y;
		else
			y-=x;
	}
	return x;
}
int main(){
	cit();
	ofstream fout("euclid2.out");
	for(i=1;i<=n;i++)
		fout<<ver(a[i][1],a[i][2])<<'\n';
	fout.close();
	return 0;
}
