#include<iostream>
#include <fstream.h> 
int t,a,b; 
int A(int a,int b) 
{ 
	if (!b)
		return a; 
	else
		return A(b,a%b); 
} 
int main() 
{ 
	int i;
	ifstream f("Euclid2.in"); 
	ofstream g("Euclid2.out"); 
	f>>t; 
	for (i=1;i<=t;--t) 
	{ 
		f>>a>>b; 
		g<<A(a,b)<<"\n"; 
	}	
	return 0; 
}

