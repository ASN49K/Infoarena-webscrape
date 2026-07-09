#include<iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int main()
{
	int A[128], B[128], n, m, MAX[256];
	fin>>n;
	fin>>m;
	for(int i=1; i<=n; i++)
		fin>>A[i];
	for(int i=1; i<=m; i++)
		fin>>B[i];
	int j = 1, z = 1, k = 1;
	for(j=1; j<=n; j++)
		for(z=1; z<=m; z++)
			if(A[j] == B[z])
				MAX[k++] = A[j];
	fout<<--k<<endl;
	for(z=1; z<=k; z++)
		fout<<MAX[z]<<" ";
	return 0;
}
