#include<iostream>
#include<fstream>
int main(){
	using namespace std;
	fstream fin("euclid2.in",ios::in) , fout("euclid2.out" , ios::out);
	int x=0,t,a,b,i,max=0,j;
	fin>>t;
	for(i=1;i<=t;i++){
		fin>>a>>b;
		for(j=1;j<=a;j++){
			if((a%j==0)&&(b%j==0)){x=j;}
		 }
		fout<<x<<endl;
		max=0;}
	return 0;
}

		