#include<fstream>

int n,m;
int A[1025][1025];
int a[1025],b[1025];

using namespace std;

ofstream g("cmlsc.out");

int max( int a,int b){ return a>b?a:b; }
void data(){

	ifstream f("cmlsc.in");


	f>>m>>n;

    int i;
	for(i=1;i<=m;i++)
		f>>a[i];

	for(i=1;i<=n;i++)
		f>>b[i];
}

void print(int i,int j){

    if(i>0 && j>0){
        if(a[i]==b[j]) {print(i-1,j-1); g<<a[i]<<' ';}
        else if( A[i-1][j] > A[i][j-1] ) print(i-1,j);
        else print(i,j-1);
    }
}

int main(){


data();
int i,j;

for(i=1;i<=m;i++){

	for(j=1;j<=n;j++){

		if( a[i]==b[j])
			A[i][j] = 1 + A[i-1][j-1] ;
		else A[i][j] = max( A[i-1][j] , A[i][j-1] );
	}
}


    g<<A[m][n]<<'\n';

print(m,n);
	return 0;
}
