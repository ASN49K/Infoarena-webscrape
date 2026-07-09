#include<fstream>
using namespace std;
#define NMax 1030
#define max(a,b) ((a > b) ? a : b)

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M,A[NMax],B[NMax],D[NMax][NMax],Sol[NMax],ind;

int main(){
	
	fin>>N>>M;
	
	for(int i=1;i<=N;i++){
		fin>>A[i];
	}
	for(int i=1;i<=M;i++){
		fin>>B[i];
	}
	
	int i,j;
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			if(A[i]==B[j])
				D[i][j]=1+D[i-1][j-1];
			else
				D[i][j]=max(D[i-1][j],D[i][j-1]);
		}
	}
	
	for(i=N,j=M;i;){
		if(A[i]==B[j])
			Sol[++ind]=A[i],i--,j--;
		else{
			if(D[i-1][j]>=D[i][j-1])
				i--;
			else
				j--;
		}
	}
	
	fout<<ind<<"\n";
	for(i=ind;i>0;i--)
		fout<<Sol[i]<<" ";
	fout<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}