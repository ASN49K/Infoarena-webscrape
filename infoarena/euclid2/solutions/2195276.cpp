#include<bits/stdc++.h>
using namespace std;int main(){ifstream fin("euclid2.in");ofstream fout("euclid2.out");int n;fin>>n;
	for(int i(0),x,y;i<n;i++,fin>>x>>y)cout<<__gcd(abs(x),abs(y))<<endl;return 0;}//Ionitas po pricolu
