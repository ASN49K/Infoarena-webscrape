#include <fstream>
using namespace std;

int cmmdc(int ,int);



int main (){

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

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

int cmmdc(int a,int b){
	int c;
	while(b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}