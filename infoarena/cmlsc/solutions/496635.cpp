#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ofstream fout("cmlsc.out");
	ifstream fin("cmlsc.in");
	int n,m;
	fin>>n>>m;
	int v1[1025], v2[1025];
	int t[256];
	for(int i=0;i<256;i++) t[i]=0;
	for(int i=0;i<n;i++){ fin>>v1[i];t[v1[i]]++;}
	for(int i=0;i<m;i++){ fin>>v2[i];t[v2[i]]++;}
	int sum=0;
	for(int i=0;i<256;i++) if(t[i]>1) sum++;
	fout<<sum<<endl;
	for(int i=0;i<256;i++) if(t[i]>1) fout<<i<<" ";
	return 0;
}