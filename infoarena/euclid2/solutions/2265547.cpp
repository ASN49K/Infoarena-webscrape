#include<bits/stdc++.h>
using namespace std;
int cmmdc(int a,int  b){
    if(b==0)return a;
    else
    return cmmdc(b,a%b);
}
int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	int t;
	cin>>t;
	int n,m;
	for(int i=1;i<=t;i++){
		cin>>n;cin>>m;
	    cout<<cmmdc(n,m)<<'\n';
	}
	return 0;
}
