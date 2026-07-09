#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int min1=min(a,b);
		int max1=max(a,b);
		while(min1>0){
			int aux=min1;
			min1=max1%min1;
			max1=aux;
		}
		cout<<max1<<endl;
	}
	return 0;
}

