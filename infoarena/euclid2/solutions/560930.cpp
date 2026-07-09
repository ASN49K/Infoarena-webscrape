#include<iostream>
#include<cstdio>
using namespace std;

int eu(int a,int b)
{
	while (a != b) 
   {if (a > b)
      a -= b;
    else 
      b -= a;
   }
  return a;
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
