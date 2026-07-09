#include <bits/stdc++.h>
using namespace std;
long long i,n,m,k;
int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>m>>k;
			while (m!=k){
		    if (k>m) k=k-m;
		    if (k<m) m=m-k;
		}
		cout<<m<<endl;
	}

	return 0;
}
