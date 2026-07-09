#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");

int main() 
 {
	int nr1,nr2,rest,x,i;\
	fin >> x;
	fin >> nr1 >> nr2;
	for (i=1;i<=x;i++){
	
	while(nr2 != 0)
	{ rest = nr1 % nr2;
	  nr1 = nr2;
	  nr2 = rest;
	}
	fout<<nr1;
}
}
