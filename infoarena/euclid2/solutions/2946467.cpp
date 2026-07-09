#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
#define cin fin
#define cout fout
long long t;
int dc(int a, int b)
	{
		if(!b) return a;
		return dc(b,a%b);
	}
int main()
	{	cin>>t;
		while(t--){
		
		int a,b;cin>>a>>b;cout<<dc(a,b)<<endl;}
	}
