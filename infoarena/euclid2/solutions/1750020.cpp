#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int x,y,r,t;

	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		cout<<euclid(x,x%y)<<endl;
	}
}

int euclid(int a,int b){
	if(b==0)return a;
	euclid(b,a%b);
}