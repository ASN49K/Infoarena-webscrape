#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
	int n;
	long a,b,r;
	
	fin>>n;

	while(fin>>a>>b){
	
		if(b==0) 
		    fout<<a<<'\n';
	    else{
			r=a%b;
			while(r){
				a=b;
				b=r;
				r=a%b;
			}
			
			fout<<b<<'\n';
		}
	}
	return 0;
	
}
