//============================================================================
// Name        : Euclid.cpp
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

void euclids(int a , int b , int *d)
{
	if(b==0)
	{
		*d = a ;
	}
	else
	{
		euclids(b,a%b,d);
	}
}
int main() {
    int i , n , a , b , *d ;
    d = new int ;
    in >> n ;
    for(i=0;i<n;i++)
    {in >> a >> b ;
    euclids(a,b,d);
    cout << *d << '\n' ;
    }
}
