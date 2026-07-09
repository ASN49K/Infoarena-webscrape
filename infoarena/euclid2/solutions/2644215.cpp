#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int cmmdc(int a,int  b){
    if(b==0)return a;
    else
    return cmmdc(b,a%b);
}
int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
	    cout<<cmmdc(n,m)<<'\n';
	}
	return 0;
}

