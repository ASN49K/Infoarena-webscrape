#include<fstream>
using namespace std;
long cmmdc(long a,long b){
	if(b==0) 
		    return a;
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
	long a,b;
	ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
	fin>>n;

	for(int i=1;i<=n;i++){
	
	    fin>>a>>b;
		fout<<cmmdc(a,b)<<'\n';
		
	}
	return 0;
	
}
