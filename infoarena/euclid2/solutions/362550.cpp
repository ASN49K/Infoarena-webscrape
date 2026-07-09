#include<fstream.h>
int a,b,d;
int main(){
	ifstream fin("date.in");
	fin>>a>>b;
	fin.close();
	while(a!=b)
		if(a>b)
			a=a-b;
		else
			b=b-a;
		d=a;
		ofstream fout("date.out");
		fout<<d;
		fout.close();
		return 0;
}

		
		
		
		