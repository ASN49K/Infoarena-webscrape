#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int x,int y){
	while(x%y){
	y=x%y;
	x=x-y;
	}
	return y;
}	
int main(){
	int n,x,y;
	fin>>n;
	while(n){
		fin>>x>>y;
		fout<<euclid(x,y)<<"\n";
		n--;
	}
	fin.close();
	fout.close();
}