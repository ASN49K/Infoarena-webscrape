#include <cstdio>
#include <iostream>
using namespace std;

int main()
{ 
	freopen("euclid2.in","r", stdin);
	freopen("euclid2.out","w", stdout);
	int a,b,c,T,i;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>a>>b;
		while(b){ c=a%b; a=b; b=c;};
		if(a>1) cout<<a;
		else if(a==1) cout<<0;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}
