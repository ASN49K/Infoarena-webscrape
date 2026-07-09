#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>


using namespace std;

void change(long long &a, long long &b){
	long long aux;
	aux=a;
	a=b;
	b=aux;
}


int main(){
	ifstream in; ofstream out;
	in.open("euclid2.in"); out.open("euclid2.out");
	out.clear();
	
	int t;
	long long a, b, c;
	
	in>>t;
	for(int i=1;i<=t;i++){
		in>>a>>b; 
		if(a<b) change(a,b);
		while((c=a%b)!=0){
			a=b; b=c; 
		} 
		out<<b<<endl;
	}
	
	
	
	in.close(); out.close();
}
