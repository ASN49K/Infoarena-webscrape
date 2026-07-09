#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int rs;
int main (){
	float N,i;
	int a,b;
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
