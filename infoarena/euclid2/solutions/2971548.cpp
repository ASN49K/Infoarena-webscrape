	#include <bits/stdc++.h>
	using namespace std;
	int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
    int c,n1,n2;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>n1>>n2;
		while(n2){
			int rest=n1%n2;
			n1=n2;
			n2=rest; 
		}
		cout<<n1<<"\n";
	}
	return 0;
}
