#include<fstream>
using namespace std;

int cmmdc(int a, int b){
	if(b==0) return a;
	else return cmmdc(b,a%b);
}

int main(){
	ifstream fin ("euclid2.in");
	ofstream fout ("euclid2.out");
	int N,a,b,i;
	fin>>N;
	for(i=1;i<=N;i++){
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
