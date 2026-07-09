#include<iostream>
#include<fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int x,int y){
	if(!y)
		return x;
	else
		return euclid(x,x%y);
}
int n,a,b;
int main(){
	fin>>n;
	while(n--){
		fin>>a>>b;
		fout<<euclid(a,b);
	}
	fin.close();
	fout.close();	
}
