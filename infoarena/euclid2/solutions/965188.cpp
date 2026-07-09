#inlclude <iostream>
#include <fstream>
using namespace std;

unsigned int cmmdc(unsigned int a, unsigned int b) 
{ 
	if(a%b == 0) 
		return b; 
	else  
		cmmdc(b, a%b); 
}

int main()
{
	int T;
	unsigned int a, b;
	ifstream in("euclid2.in");
	ofstream out;
	out.open("euclid2.out");
	in >> T;
	for(int i = 0; i  < T; i++)
	{
		in >> a >> b;
		out << cmmdc(a, b);
		
	}
}
