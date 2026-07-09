#include<bits/stdc++.h>

using namespace std ;

const int NMAX  = 257 ;


ifstream fin("cmlsc.in") ;
ofstream fout("cmlsc.out") ;

int N, M, BEST, D[NMAX][NMAX], A[NMAX], B[NMAX], sol[NMAX] ;

int main()
{

    fin >> M ;
    fin >> N ;

    for(int i = 1 ; i <= M ; ++ i)
        fin >> A[i] ;

    for(int j = 1 ; j <= N ; ++ j)
        fin >> B[j] ;


    for(int i = 1 ; i <= M ; ++ i)
        for(int j = 1 ; j<= N ; ++ j)
            if(A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else D[i][j] = max(D[i - 1][j], D[i][j - 1]) ;


    for(int i = M, j = N; i;)
        if(A[i] == B[j])
    {
        sol[++ BEST] = i;
       -- i  ;
       -- j  ;
    }
    else if(D[i][j - 1] < D[i - 1][j])
        -- i ;
    else -- j ;


    fout << BEST << '\n';

    for(int i = BEST; i ; i --)
        fout << A[sol[i]] << ' ' ;

    fout << '\n' ;



    fin.close() ;
    fout.close() ;
    return 0 ;
}
