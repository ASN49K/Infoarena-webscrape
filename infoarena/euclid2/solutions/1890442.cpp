#include<bits/stdc++.h>
using namespace std;

int n,a,b;

int cmd(int b,int a)
{
	if(!a) return b;
    return cmd(a,b%a);
}

int main()
{
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	cin>>n;
	for(; n;--n)
	 {
	 cin>>a>>b;
	 cout<<cmd(a,b)<<"\n";}
return 0;
}
