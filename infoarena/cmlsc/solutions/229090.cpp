#include <fstream.h>

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    
    int A[200], M, B[200], N, C[200], p, i, j;
    
    fin >> M >> N;
    
    for ( i = 0; i < M; i++ )
        fin >> A[i];
    
    for ( j = 0; j < N; j++ )
        fin >> B[j];
    
    p = 0;
    int gasit;
    
    for ( i = 0; i < M; i++ )
    {
        for ( j = 0; j < N; j++ )
        gasit = 0;
        if ( A[i] == B[j] )
        gasit = 1; 
    }
    int MAX = 0;
    if ( !gasit )
    {
       C[p++] = A[i];
       MAX++;  
    }
     
    for ( i = 0; i < p; i++ )
    {    
         fout << MAX << '\n'; 
         fout << C[i] << ' ';
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
