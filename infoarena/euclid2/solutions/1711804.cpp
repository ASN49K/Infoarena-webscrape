#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int N;
int main (){
float i,a,b,rs;
	for(i=1;i<=N;i++)
	{
		fin>>a>>b;
		while (b!=0)
		{
			rs=a%b;
			a=b;
			b=rs;	
		}
	fout<<a<<"\n";	
	}
	return 0;
}
