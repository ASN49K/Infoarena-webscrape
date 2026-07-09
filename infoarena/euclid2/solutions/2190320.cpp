#include <iostream>
using namespace std;
int cmmdc(int a, int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
		
	}
	return a;
}
int main(){
	int T,x,y,i;
	freopen("euclid2.in" , "r", stdin);
	freopen("euclid2.out" , "w" ,stdout);
	cin>>T;
	for(i=1 ; i<=T ; i++){
		cin>>x>>y;
		cout<<cmmdc(x,y)<<endl;
	}
	return 0;
}