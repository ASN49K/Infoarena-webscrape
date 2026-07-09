#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a , int b){
	
	while (a!= 0 && b != 0) {
		if (a > b)
			a%=b;
		else 
			b%=a;
	}

	return a+b;

	/*
	int r;
	while (a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
	*/
}

int main()
{	
	int x ,a ,b ; 

	fin>> x;
	
	for (int i = 1 ; i <= x ; i ++ ) {
		fin >>a >> b;
		
		fout << cmmdc(a,b) << endl;
	}
}


