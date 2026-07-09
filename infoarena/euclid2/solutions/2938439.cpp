#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;
		 
int main()
{	int a,b,i,verifier=0;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>a>>b;
	if(a>b)
		i=b+1;
	else
		i=a+1;
while(verifier==0)
{	i--;
	if(a%i==0 && b%i==0)
		verifier=1;
	if(i==1)
		verifier=1;	
}
fout<<i;
}
