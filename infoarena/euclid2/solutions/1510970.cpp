#include <fstream>

using namespace std;
long long T,a[100000],b[100000];
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b){
	if (b==0) return a;
	return euclid(b,a%b);
}
int main(){
	fin>>T;
	for(int i=1; i<=T; i++)
	fin>>a[i]>>b[i];
	for(int i=1; i<=T; i++)
	fout<<euclid(a[i],b[i])<<endl;
	return 0; 
}
