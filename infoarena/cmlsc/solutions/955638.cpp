#include<iostream>
#include<fstream>
#define FOR( i, a, b) for(i=a;i<=b;i++)
#define NMAX 1024 
#define maxim(a,b) ((a > b) ? a : b)
using namespace std;
int A[NMAX],B[NMAX],LCS[NMAX][NMAX],sir[NMAX],N,M;	
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{f>>M>>N;
int i,j,sol,l=1;
FOR (i, 1, M)
f>>A[i];
FOR (i, 1, N)
f>>B[i];
    FOR (i, 1, M)
        FOR (j, 1, N)
		{if(A[i]==B[j])
			LCS[i][j]=1+LCS[i-1][j-1];
		else 
			LCS[i][j]=maxim(LCS[i-1][j],LCS[i][j-1]);
		}
		
		g<<LCS[M][N]<<"\n";
sol=LCS[M][N];

 for(i=M;i;i--)
	 for(j=N;j;j--)
		 if(A[i]==B[j]&& LCS[i][j]==sol)
		 {sol--;
		 sir[++l]=A[i];
		 
		 }
		
		 for(i=l;i>1;i--)
			 g<<sir[i]<<" ";


return 0;
}
