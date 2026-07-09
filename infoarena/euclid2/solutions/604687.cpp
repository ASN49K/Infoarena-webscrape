#include <fstream>
#include<iostream>
using namespace std;
#include <stdio.h>

template <class Type>
Type cmmdc ( Type a ,Type b )
{
	while ( b!=0 )
	{
		Type t = b;
		b = a % b;
		a = t;
	}

return a;
}


int main()
{
//ifstream input("euclid2.in");
//ofstream output("euclid2.out");

FILE *input, *output;
input = fopen ( "euclid2.in","r");
output = fopen ("euclid2.out","w");

int T;
int a ,b;

fscanf (input,"%d", &T);

	for(int i =1 ; i<= T; i++)
	{
		//input>>a>>b;
		//output<<cmmdc( a,b ) <<endl;
		fscanf (input, "%d%d",&a,&b );
		fprintf (output ,"%d\n", cmmdc(a,b));

	}



	return 0;
}

