#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	if(b == 0) {
		return a;
	} else {
		return cmmdc(b, a % b);
	}
}

int main() 
{
	ifstream in; in.open("euclid2.in");
	ofstream out; out.open("euclid2.out");
	int i = 0, n = 0, a = 0, b = 0;
	in >> n;
	while(i < n) 
	{	
		in>>a>>b;
		out<<cmmdc(a, b)<<"\n";
		i++;
	}


	in.close();
	out.close();
	return 0;
}
