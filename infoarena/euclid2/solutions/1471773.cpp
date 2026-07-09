#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a , int b){
	
	if (a > b) {
		if (a % b == 0)
		return b;
			return cmmdc(a%b,b);
		
	}else if (b > a) {
		if (b % a == 0)
		return a;	
			return cmmdc(a , b % a);
	}else 
		return a;

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


