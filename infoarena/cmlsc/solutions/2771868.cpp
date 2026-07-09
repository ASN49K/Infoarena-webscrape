#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024], b[1024], v[1024];
int main(){
	int m, n; cin>>m>>n;
    for (int i=0; i<m; ++i) cin>>a[i];
    for (int i=0; i<n; ++i) cin>>b[i];
    int c=0;
    for (int i=0; i<m; ++i){
    	for (int j=0; j<n; ++j){
    		if (a[i]==b[j]){
    			v[c]=a[i];
    			++c;
    		}
    	}
    }
    cout<<c<<'\n';
    for (int i=0; i<c; ++i){
    	cout<<v[i]<<' ';
    }
    return 0;
}