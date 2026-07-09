#include <fstream>
using namespace std;

int C[256],D[256];

int main (){

	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int M,N,A[100],B[100],k=0,x=0,p=1;
	fin>>M>>N;
	for(int i=0;i<M;i++)
		fin>>A[i];
	for(int i=0;i<N;i++)
		fin>>B[i];

	if(M>N){
		for(int i=0;i<M;i++)
			C[A[i]]=p++;
		for(int i=0;i<N;i++)
			if(C[B[i]] && C[B[i]]>k)
				D[x++]=B[i];
	}
	else{
		for(int i=0;i<N;i++)
			C[B[i]]=p++;
		for(int i=0;i<M;i++)
			if(C[A[i]] && C[A[i]]>k)
				D[x++]=A[i];
	}
	
	fout<<x<<"\n";
	for(int i=0;i<x;i++)
		fout<<D[i]<<" ";
	fin.close();
	fout.close();

}

