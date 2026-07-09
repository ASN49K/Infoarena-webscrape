#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int cmmdc(int a,int b){
	while (b!=0){
		int rem=a%b;
		a=b;
		b=rem;
	}
	return a; 
}

int main(){
	int n;
	fin>>n;
	for (int i=1;i<=n;++i){
		int a,b;
		fin>>a>>b;
		std::cout<<cmmdc(a,b)<<'\n';
	}
	return 0;
}
