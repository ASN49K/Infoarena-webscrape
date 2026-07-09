#include "stdio.h"
int N,A,B;
int gcd(int a,int b){
	if (!b) return a;
	else return gcd(b,a%b);
}
void main(){
	freopen("euclid2.in","r",cin);
	freopen("euclid2.out","w",cout);
	cin>>N;
	for (int i=0;i<N;i++){
		cin>>A>>B;
		cout<<gcd(&A,&B);
	}
}