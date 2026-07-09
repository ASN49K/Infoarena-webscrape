#include<iostream>
#include<fstream>
int main(){
	using namespace std;
	fstream fin("euclid2.in",ios::in) , fout("euclid2.out" , ios::out);
	int x,t,a,b,i,max=0,j;
	fin>>t;
	for(i=1;i<=t;i++){
		fin>>a>>b;
		if(a>b){max=a;}
		else{max=b;}
		for(j=1;j<=max;j++){
			if((a%j==0)&&(b%j==0)){x=j;}
		 }
		fout<<x<<endl;
		max=0;}
	return 0;
}

		