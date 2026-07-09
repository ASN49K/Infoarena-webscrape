#include<bits/stdc++.h>

using namespace std ;
const short NMAX  = 1024 ;
ifstream fin("cmlsc.in") ;
ofstream fout("cmlsc.out") ;
short N, M, BEST, D[NMAX][NMAX], A[NMAX], B[NMAX], sol[NMAX] ;

int main()
{
    fin >> M >> N ;

    for(short i = 1 ; i <= M ; ++ i)
        fin >> A[i] ;

    for(short i = 1 ; i <= N ; ++ i)
        fin >> B[i] ;

    for(short i = 1 ; i <= M ; ++ i)
        for(short j = 1 ; j <= N ; ++ j)
            if(A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else D[i][j] = max(D[i - 1][j], D[i][j - 1]) ;


    for(short i = M, j = N; i;)
        if(A[i] == B[j])
        {
            sol[++ BEST] = i;
            -- i  ; -- j  ;
        }
        else if(D[i][j - 1] > D[i - 1][j])
            -- j ;
        else -- i ;

    fout << BEST << '\n';

    for(short i = BEST; i ; i --)
        fout << A[sol[i]] << ' ' ;

    fout << '\n' ;
    fin.close() ;
    fout.close() ;
    return 0 ;
}
