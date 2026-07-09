#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

vector<int> cmls(vector<int>& v1, vector<int>& v2)
{
	int N=v1.size()-1; int M=v2.size()-1;
	vector<vector<int>> L(N+1,M+1);
	vector<int>rez;
	
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j)
			if (v1[i]==v2[j])
				L[i][j]=1+L[i-1][j-1];
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);

	for (int i=N, j=M; i;)
		if (v1[i]==v2[j]) rez.push_back(v1[i]), --i,--j;
		else if (L[i-1][j]<L[i][j-1]) --j;
				else --i;

	return rez;

}

int main()
{
	int N,M,poz2; 
	ifstream fin("in.txt",ios::in);
	ofstream fout("out.txt",ios::out);
	
	fin>>N>>M;

	vector<int> v1(N+1), v2(M+1), rez;

	for (int i=1; i<=N; ++i) fin>>v1[i];
	for (int i=1; i<=M; ++i) fin>>v2[i];

rez=cmls(v1,v2);
fout<<rez.size()<<endl;
for (int i=rez.size()-1; i>=0; --i) fout<<rez[i]<<" ";
	
	
}
