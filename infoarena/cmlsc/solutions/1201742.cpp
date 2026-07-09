#include<iostream>
#include<fstream>
using namespace std;
#define MAX 1024
int m,n,A[MAX],B[MAX],C[MAX];

void citire(const char *path)
{
	ifstream f(path);
	f>>m>>n;
	for(int i=0;i<m;i++)
		  f>>A[i];
	for(int i=0;i<n;i++)
		f>>B[i];

	f.close();

}
void afis()
{
	ofstream f("cmlsc.out");

	int nr=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(A[i]==B[j])
				C[nr++]=A[i];
	cout<<nr<<endl;
	for(int i=0;i<nr;i++)
		 cout<<C[i]<<" ";

	f.close();
}
int main()
{
	citire("cmlsc.in");
	afis();
	return 0;
}
