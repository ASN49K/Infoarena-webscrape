#include <cstdio>
#include <iostream>
using namespace std;

int main()
{ 
	int a,b,c,T,i;
	freopen("euclid2.in","r", stdin);
	freopen("euclid2.out","w", stdout);
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>a>>b;
		while(b){ c=a%b; a=b; b=c;};
		cout<<a<<endl;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}
