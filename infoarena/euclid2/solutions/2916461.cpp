/*
 * hello.cpp
 *
 *  Created on: Jul 29, 2022
 *      Author: xszero
 */



#include <iostream>
using namespace std;
int main() {
   int t;
   int x1,x2;
   cin>>t;
   while(t)
   {
	   int sw;
	   cin>>x1>>x2;
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
	   cout<<x1;
   }
}


