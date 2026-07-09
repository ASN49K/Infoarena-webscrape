#include <iostream>
#include <fstream>
 
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


void euclid2(int a,int b){
	int r=1;
	while (r!=0){
		r=a%b;
		a=b;
		b=r;
	}
	fout<<a<<"\n";
}
 
 
int main(){
	int i,j,x,y,n; 
	fin>>n;
	for (i=1;i<=n;i++){
	fin>>x>>y;
	x>y?euclid2(x,y):euclid2(y,x);}
fin.close();
fout.close();
return 0;
}
