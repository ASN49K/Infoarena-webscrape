#include<fstream>
using namespace std;
#define MAXN 1024
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define maxim(a,b) ((a>b)?a:b)
   ifstream cin("cmlsc.in");
   ofstream cout("cmlsc.out");
int M,N,A[MAXN],B[MAXN],sir[MAXN],D[MAXN][MAXN],bst;
void backtrack(int i,int j) {
	 if( i==0 || j==0 ) return;
	 if (A[i]==B[j]) {
	                 sir[++bst]=A[i];
					 return backtrack(i-1,j-1); }
	else 				 
	if(D[i][j-1]>D[i-1][j]) return backtrack(i,j-1);
	                      else return backtrack(i-1,j);
}
int main() {
	int i,j;
	cin>>M>>N;
	FOR(i,1,M)
          cin>>A[i];          
	FOR(j,1,N)
          cin>>B[j];        
    FOR(i,1,M)
     FOR(j,1,N)
	   		if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
			   else D[i][j]= maxim(D[i-1][j],D[i][j-1]);
	backtrack(M,N);
	cout<<bst<<"\n";
	for(i=bst;i;i--)
	    cout<<sir[i]<<" ";  
	return 0;
}
				                 
