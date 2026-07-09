#include<bits/stdc++.h>
using namespace std;
int n;
long long a,b;
int euclid(int x, int y){
	bool check=true;
	while(check){
		if(y==0)break;else{
		x-=y;
		if(x<y){
			int aux=x;
			x=y;
			y=aux;
		}
	}
	}
	return x;
}
int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int min1=min(a,b);
		int max1=max(a,b);
		cout<<euclid(max1,min1)<<"\n";
	}
	return 0;
}
