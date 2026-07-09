#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long cmmdc(long a, long b){
	if(b==0) return a;
	long r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	int n;
	long x,y;
	
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>x>>y;
		fout<<cmmdc(x,y)<<endl;
	}
	fout.close();
	
}
