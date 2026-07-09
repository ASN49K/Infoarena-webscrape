#include<bits/stdc++.h>

using namespace std;

int cmmdc(int a,int b){
	if(b==0) return a;
	else return cmmdc(b,a%b);
}

int n,x,y;

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cout<<cmmdc(x,y)<<endl;
	}
	return 0;
}
