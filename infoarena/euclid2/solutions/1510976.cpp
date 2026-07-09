#include <fstream>

using namespace std;
int T,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b){
	if (b==0) return a;
	return euclid(b,a%b);
}
int main(){
	fin>>T;
	while(T--){
		fin>>a>>b; fout<<euclid(a,b)<<endl;
	}
	return 0; 
}
