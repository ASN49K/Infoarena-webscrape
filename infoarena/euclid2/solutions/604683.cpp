#include <fstream>
#include<iostream>
using namespace std;

template <class Type>
int cmmdc ( int a ,int b )
{
	while ( b!=0 )
	{
		int t = b;
		b = a % b;
		a = t;
	}

return a;
}


int main()
{
fstream input("euclid2.in");
fstream output("euclid2.out");
int T;
int a ,b;

input>> T;

	for(int i =1 ; i<= T; i++)
	{
		input>>a>>b;
		output<<cmmdc( a,b ) <<endl;

	}



	return 0;
}

