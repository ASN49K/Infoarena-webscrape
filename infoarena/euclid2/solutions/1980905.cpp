#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>


using namespace std;


int cmmdc(int a, int b){
   if(b==0) return a;
   cmmdc(b,a%b);
}


int main(){
	ifstream in; ofstream out;
	in.open("euclid2.in"); out.open("euclid2.out");
	out.clear();
	
	int t;
	int a, b;
	
	in>>t;
	for(int i=1;i<=t;i++){
		in>>a>>b; 
		out<<cmmdc(a,b)<<endl;
	}
	
		
	in.close(); out.close();
	return 0;
}
