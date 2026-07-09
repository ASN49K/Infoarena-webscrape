#include<iostream>
#include<cstdio>
using namespace std;

int eu(int a, int b)
{
    if (!b) 
	return a;
    return eu(b, a % b);
}

int main()
{
	int n,m,t;
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{	
	  cin>>n>>m;
	  cout<<eu(n,m)<<endl;
	}  
	
	return 0;
}
