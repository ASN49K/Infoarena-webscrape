/*
 * hello.cpp
 *
 *  Created on: Jul 29, 2022
 *      Author: xszero
 */



#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main() {
   int t;
   int x1,x2;
   f>>t;
   while(t--)
   {
	   int sw;
	   f>>x1>>x2;
	   while(x2!=0)
	   {
		   if(x1>x2) {
			  sw=x2;
			  x2=x1%x2;
			  x1=sw;
		   }
		   else {
			   sw=x1;
			   x1=x2%x1;
			   x2=sw;
		   }
	   }
	   g<<x1;
   }
}


