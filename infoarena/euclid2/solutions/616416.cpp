#include <cstdio>
#include <iostream>
using namespace std;

int main()
{ 
	freopen("euclid2.in","r", stdin);
	freopen("euclid2.out","w", stdout);
	int a,b,c,T,i;
	cin>>T;
	for(i=1;i<T;i++)
	{
		cin>>a>>b;
		while(b){ c=a%b; a=b; b=c;};
		cout<<a<<endl;
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
}
