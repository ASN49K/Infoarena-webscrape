#include <fstream>

using namespace std;

int cmmdc(int a,int b){
	if(a==b)return a;
	else if(a>b)return cmmdc(a-b,b);
	else return cmmdc(a,b-a);
}
int main(){
	fstream fin("euclid2.in",ios::in);
	fstream fout("euclid2.out",ios::out);
	int a,b,n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	fin.close();
	fout.close();
}