#include <fstream>


using namespace std;
FILE *f = fopen("cmlsc.in" ,"r");
FILE *g = fopen("cmlsc.out","w");



int M, N, A[1025], B[1025], D[1025][1025], sir[1025], bst;





int main()
{
    fscanf(f,"%d %d", &M, &N);


    for ( int i = 1 ; i <= M ; i++ )
        fscanf(f,"%d", &A[i]);

    for ( int i = 1 ; i <= N ; i++ )
        fscanf(f,"%d", &B[i]);
    ///CITIRE


    for ( int i = 1 ; i<=M ; i++ )
        for ( int j = 1 ; j<=N ; j++ )
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    int i = M, j = N;
    while ( i>0 && j>0 )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else
        {
            if (D[i-1][j] < D[i][j-1])
                j--;
            else
                i--;
        }
    ///AFISARE
    fprintf(g,"%d\n", bst);
    for ( int i = bst ; i>0 ; i-- ) fprintf(g,"%d ", sir[i]);
}
