#include <fstream>
#include<iostream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
	int j,i,t,n,x,s;
	in>>t;
	for(i=1;i<=t;i++)
	{
		in>>n;
		s=0;
		for(j=1;j<=n;j++)
		{
			in>>x;
			s=s^x;
			cout<<s<<" ";
		}
		if(s)
			out<<"DA"<<endl;
		else
			out<<"NU"<<endl;
	}
	in.close();
	out.close();
	return 0;
}
