#include <fstream>

#define MAX(a,b) (a>b)?a:b;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define NMAX  5000

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m, D[NMAX][NMAX], Sir[NMAX], N[NMAX],M[NMAX],bst;


int main(){

	in >> n >> m;
	FOR(i,1,n)
	 in>>N[i];
	FOR(i,1,m)
	 in>>M[i];

	FOR(i,1,n)
		FOR(j,1,m)
			if(N[i]==M[j]) D[i][j]=1+D[i-1][j-1];
			else D[i][j]=MAX(D[i][j-1],D[i-1][j]);
    out<<D[n][m]<<"\n";
	for(int i=n,j=m;i && j;){
        if(N[i]==M[j])
            Sir[++bst]=N[i], i--,j--;
        else if(D[i][j-1]<D[i-1][j]) --i;
            else --j;
	}
	while(bst) out<<Sir[bst--]<<" ";
		return 0;
}
