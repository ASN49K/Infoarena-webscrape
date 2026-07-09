//test compilare in Cygwin64 Terminal
#include <iostream>
#include <fstream>
using namespace std;
int n,a,b;

int euclid(int a, int b){
	if(0==b){
		return a;
	} 
	return euclid(b,a%b);
}
 
 
int main()
{   ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
	while(n>0){
		in>>a>>b;
		out<<euclid(a,b)<<'\n';
		n--;
	}
    in.close();
    out.close();
    return 0;
}
