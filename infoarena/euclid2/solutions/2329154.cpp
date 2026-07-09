// Euclid2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include <conio.h>

#include <iostream>
#include <fstream>

using namespace std;

int T, a, b;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
	if (!b) 
		return a;
	
	else
		euclid(b, a % b);
}
int main()
{
	in >> T;
	while(T--)
	{
		in >> a;
		in >> b;
		out << euclid(a, b) << "\n";
	}
	//_getche();
    return 0;
}

