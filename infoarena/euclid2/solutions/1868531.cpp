#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ofstream out;
ifstream in;
unsigned char c[2000000];
int main(){
    in.open("euclid2.in");
    out.open("euclid2.out");
    int a,b,t;
    in>>t;
	for(int i=1; i<=t; ++i){
		in>>a>>b;
		while(a && b){
			if(a>b)a=a%b;
			else b=b%a;
		}
		out<<a+b<<endl;
	}
    return 0;
}
