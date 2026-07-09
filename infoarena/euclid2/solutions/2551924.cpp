#include<bits/stdc++.h>
using namespace std;

int cmmdc(int a,int b){
	int r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
	int t,a,b;
	in>>t;
	for(int i=0;i<t;i++){
		in>>a>>b;
		cmmdc(a,b);
	}
}