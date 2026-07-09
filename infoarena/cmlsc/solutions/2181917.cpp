#include<bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int C[1025][1025],A[1025],B[1025],m,n,D[1025],k,i,j;
int main()
{
fin>>n>>m;
	for(i=1;i<=n;i++) fin>>A[i];
	for(j=1;j<=m;j++) fin>>B[j];
	
		for(i=0;i<=n;i++) C[i][0]=0;
					for(j=0;j<=m;j++) C[0][j]=0;
					
		for(i=1;i<=n;i++)
					for(j=1;j<=m;j++)
							if(A[i]==B[j]) C[i][j]=C[i-1][j-1]+1;
											else C[i][j]=max(C[i-1][j],C[i][j-1]);
			fout<<C[n][m];
			fout<<endl;
i=n; j=m; k=0;
    while(C[i][j])
    {
    	if(A[i]==B[j]){
    		k++;
    		D[k]=A[i];
    		i--; j--;}
    		else if (C[i][j]==C[i-1][j]) i--; 
    		else  j--;
		}
	
	   for(i=k; i>=1; i--)
        fout<<D[i]<<' ';

return 0;
}
