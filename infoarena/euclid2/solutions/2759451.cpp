#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");

int main() 
 {
	int nr1,nr2,rest,x,i;\
	fin >> x;
		for (i=1;i<=x;i++){
	fin >> nr1 >> nr2;

	
	while(nr2 != 0)
	{ rest = nr1 % nr2;
	  nr1 = nr2;
	  nr2 = rest;
	}
	fout<< nr1 << "\n";
}
}
