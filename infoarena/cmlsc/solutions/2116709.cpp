#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[2000],B[2000],m,n,C[2000][2000],P[2000][2000];

int main(){
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>A[i];
	for(int i=1;i<=n;i++)
		cin>>B[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i]==B[j]){
				C[i][j]=C[i-1][j-1]+1;
			}
			else
				if(C[i-1][j]>=C[i][j-1])
					C[i][j]=C[i-1][j];
				else
					C[i][j]=C[i][j-1];
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++)
//			cout<<C[i][j]<<" ";
//		cout<<"\n";
//	}
	cout<<C[m][n];
	
	
	
	return 0;
}

