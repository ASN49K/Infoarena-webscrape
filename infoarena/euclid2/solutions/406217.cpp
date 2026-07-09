#include <fstream.h>
#include <iostream.h>
ofstream fout("euclid2.out");
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
	if(x==y)
		return x;
	if(x>y)
		return ver(x-=y,y);
	else
		return ver(x,y-=x);
}
int f(int k){
	if(k>n)
		return 0;
	fout<<ver(a[k][1],a[k][2])<<'\n';
	return f(k+1);
}
int main(){
	cit(); f(1);
	//for(i=1;i<=n;i++)
		//fout<<ver(a[i][1],a[i][2])<<'\n';
	fout.close();
	return 0;
}
