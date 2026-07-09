#include <fstream>
using namespace std;



int cmmdc(int a,int b){
	int c;
	while(b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}

int main (){

	ifstream fin("euclid.in");
	ofstream fout("euclid.out");

	int a,b,T;
	fin>>T;
	while(T){
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
		T--;
	}

	fin.close();
	fout.close();

}
