#include <fstream>
using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

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
	int a,b,T;
	fin>>T;
	while(T){
		fin>>a>>b;
		fout<<cmmdc(a,b);
		T--;
	}

}
