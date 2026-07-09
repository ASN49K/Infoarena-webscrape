#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b){
	if (b==0) return a;
	return euclid(b,a%b);
}
int main(){
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T;	
	fin>>T;
	while(T--){
		int a,b;
		fin>>a>>b; 
		fout<<euclid(a,b)<<endl;
	}
}
