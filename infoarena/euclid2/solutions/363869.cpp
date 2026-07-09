#include <fstream>

using namespace std;

int main(){
	fstream fin("euclid2.in",ios::in);
	fstream fout("euclid2.out",ios::out);
	int a,b,c,n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a>>b;
		while(b>0){
			c=a%b;
			a=b;
			b=c;
		}
		fout<<a;
	}
	fin.close();
	fout.close();
}