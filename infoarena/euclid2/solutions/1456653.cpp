#include<fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
	
int T,a,b;
int main(){
	fin >> T;
	for(int i = 0;i<T;i++){
		fin >> a >> b;
		fout << gcd(a,b) << '\n';
	}
	return 0;
}
