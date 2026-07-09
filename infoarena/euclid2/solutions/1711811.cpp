#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int N;
int main (){
	fin>>N;
	long long int a,b;
	int i;
	for(i=1;i<=N;i++)
	{
		fin>>a>>b;
		while (b!=0)
		{
			a=b;
			b=a%b;	
		}
	fout<<a<<"\n";	
	}
	return 0;
}
