#include <iostream>
using namespace std;
int cmmdc(int a, int b){
	int r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	int T,x,y,i;
	freopen("euclid2.in" , "r", stdin);
	freopen("eucid2.out" , "w" ,stdout);
	cin>>T;
	for(i=1 ; i<=T ; i++){
		cin>>x>>y;
	}
	cout<<cmmdc(x,y)<<endl;
	return 0;
}