#include <fstream>
using namespace std;
int N,M;
#define _a 1026
int A[ _a ],B[ _a ],L[ _a ][ _a ];
ofstream g("cmlsc.out");

void afis( int x, int y , int k  ){
    if(!k) return ;
    if(A[x]==B[y])
        {
            afis(x-1,y-1,k-1);
            g<<A[x]<<" ";
        }
        else if(L[x-1][y]>L[x][y-1])afis(x-1,y,k);
                else afis(x,y-1,k);

}

int main()
{
   ifstream f("cmlsc.in");
   f>>N>>M;
   for( register int i=1; i<=N; ++i)
      f>>A[i];
   for( register int i=1; i<=M; ++i)
      f>>B[i];
    f.close();
    for(register int i=1;i<=N;++i )
        for(register int j=1;j<=M;j++){
            if( A[i] == B[j] )    L[i][j]=L[i-1][j-1]+1;
            else L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    g<<L[N][M]<<'\n';
    afis(N,M,L[N][M]);


    return 0;
}
