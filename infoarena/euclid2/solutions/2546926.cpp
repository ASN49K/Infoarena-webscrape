#include <bits/stdc++.h>
using namespace std;

int n,x,y;
struct {
	int t1,t2;
}a[100010];

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].t1>>a[i].t2;
	for (int i=1;i<=n;i++) cout<<gcd(a[i].t1,a[i].t2)<<'\n';
return 0;
}
