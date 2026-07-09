//============================================================================
// Name        : Algoritm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a , int b)
{
	int c ;
	while(b)
	{
		c = a % b ;
		a = b ;
		b = c ;
	}
	return a ;
}

int main() {
	int a , b , nr , i ;
	in >> nr ;
	for(i=0;i<nr;i++) {
    in >> a >> b ;
    out << cmmdc(a,b);
	}
}
