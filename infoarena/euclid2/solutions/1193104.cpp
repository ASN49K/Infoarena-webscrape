#include<fstream>
using namespace std;
long cmmdc(long a, long b){
	long r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	long n;
	long x,y;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	for(long i=1;i<=n;i++){
		fin>>x>>y;
		fout<<cmmdc(x,y)<<endl;
	}
	fout.close();
	
}
