#include <bits/stdc++.h>

using namespace std ;


const int NMAX = 1024 ;

ifstream fin("cmlsc.in") ;
ofstream fout("cmlsc.out") ;

int N, M, A[NMAX], B[NMAX], D[NMAX][NMAX], best, sir[NMAX];


int main()
{
    fin >> N >> M ;


    for(int i = 1 ; i <= N ; ++ i )
        fin >> A[i] ;

    for(int j = 1 ; j <= M ; ++ j)
        fin >> B[j] ;

    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= M ; ++ j)
            if(A[i] == B[j])
                D[i][j] = D[i - 1][j - 1]  + 1;
            else
                D[i][j] = max(D[i][j - 1], D[i - 1][j]) ;



            for(int i = N, j = M; i;)
            if(A[i] == B[j])
            {

                sir[++ best] = A[i] ;
                -- i ;
                -- j ;

            }
            else if(D[i - 1][j] < D[i][j - 1])
                -- j;

            else -- i ;

            fout << best << '\n' ;


            for(int i = best ; i ; i --)
                fout << sir[i] << ' ' ;

    fin.close() ;
    fout.close() ;
    return  0 ;
}
