#include <fstream>
using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int main (){
	int a,b,c,T;
	fin>>T;
	do
	{
		fin>>a>>b;
		while(b!=0){
			c=b;
			b=a%b;
			a=c;
		}
		fout<<a<<"x";	
		T--;
	}
	while(T);

}
